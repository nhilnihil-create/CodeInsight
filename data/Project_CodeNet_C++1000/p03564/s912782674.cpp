#include <stdio.h>
int main(){
	//jadi soalnya tu
	//selama hasilnya blm > dari k
	//jalanin program A
	//kalo udah baru tambahin
	int jalan, k;
	scanf("%d", &jalan);
	scanf("%d", &k);
	
	int dariSoal=1;
	
	for(int i=0; i<jalan; i++){
		if(dariSoal<k){
			dariSoal *= 2;
		} else {
			dariSoal += k;
		}
	}
	printf("%d\n", dariSoal);
	return 0;
}