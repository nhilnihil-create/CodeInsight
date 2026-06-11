#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int a, b;
	scanf("%d %d", &a, &b);
	int ribuan, ratusan, puluhan, satuan;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		int jumlah = 0;
		if(i > 9999){
			sum += i;
		}else if(i > 999){
			ribuan = i / 1000;
			ratusan = (i / 100) - (ribuan * 10);
			puluhan = (i / 10) - ((i / 100) * 10);
			satuan = i % 10;
			jumlah = ribuan + ratusan + puluhan + satuan;
			if(jumlah >= a && jumlah <= b){
				sum += i;
			}
		}else if(i > 99){
			ratusan = i / 100;
			puluhan = (i / 10) - (ratusan * 10);
			satuan = i % 10;
			jumlah = ratusan + puluhan + satuan;
			if(jumlah >= a && jumlah <= b){
				sum += i;
			}
		}
		else if(i > 9){
			puluhan = i / 10;
			satuan = i % 10;
			jumlah = puluhan + satuan;
			if(jumlah >= a && jumlah <= b){
				sum += i;
			}
		}
		else{
			if(i >= a && i <= b){
				sum += i;
			}
		}
//		printf("saat %d sum = %d\n", i, sum);
		if(jumlah != 0){
//			printf("jumlah setelah ditambah oleh %d = %d\n", i, jumlah);
		}
	}
	printf("%d\n", sum);
	return 0;
}