// Import library yang diperlukan diprogram ini
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Buat struct tanggal_lahir (isi : tahun, bulan, tanggal)
typedef struct{
	int tahun;
	int bulan;
	int tanggal;
} tanggal_lahir;

// Buat struct data_orang (isi : nama, struct tanggal_lahir)
typedef struct{
	char nama_orang[255];
	tanggal_lahir tl;
} data_orang;

// Buat function->struct dengan nama buat_data 
data_orang *buat_data(const char *nama, int tahun, int bulan, int tanggal){
    data_orang *data_baru = (data_orang*)malloc(sizeof(data_orang));
    
    strcpy(data_baru->nama_orang, nama);
    
    data_baru->tl.tahun   = tahun;
    data_baru->tl.bulan   = bulan;
    data_baru->tl.tanggal = tanggal;
    
    return data_baru;
}

void hapus_data(data_orang *seseorang){
	free(seseorang);
}

void tampilkan_data(data_orang *seseorang, int urutan){
    printf(" [#] Nama Orang ke-%d : %s\n", urutan, seseorang->nama_orang);
    printf(" [#] Tanggal Lahir   : %d/%d/%d\n", seseorang->tl.tanggal, seseorang->tl.bulan, seseorang->tl.tahun);
    printf("\n");
}

int main(){
	int dat, inc, thn = 0, bln = 0, tgl = 0;
	char nama[255];
	
	printf("== [ Input ] ==\n\n");
	
	printf("[#] Berapa banyak data? ");
	scanf("%d", &dat);
	
	// Bersihkan layar konsol cmd
	system("cls||clear");
	
    data_orang *person[dat];
    
    printf("== [ Input ] ==\n\n");
    
    for(inc = 0; inc < dat; inc++){
    	tgl = 0;
    	bln = 0;
    	thn = 0;
    	
    	printf("[#] Masukkan nama orang ke-%d          : ", inc+1);
    	scanf(" %[^\n]s", nama);
    	
    	printf("[#] Masukkan tanggal lahir orang ke-%d : [hh/bb/yy] ", inc+1);
    	scanf(" %d/%d/%d", &tgl, &bln, &thn);
    	
    	printf("\n");
    	
		person[inc] = buat_data(nama, thn, bln, tgl);
	}
    
    // Bersihkan layar konsol cmd
	system("cls||clear");
    
    printf("== [ Output ] ==\n\n");
    
    printf("[#] Berfore : \n\n");
    
    for(inc = 0; inc < dat; inc++){
    	tampilkan_data(person[inc], inc+1);
	}
    
    // Hapus nama orang
    hapus_data(person[0]);
    
    printf("[#] After : \n\n");
    
    for(inc = 0; inc < dat; inc++){
    	tampilkan_data(person[inc], inc+1);
	}
    
    return 0;
}
