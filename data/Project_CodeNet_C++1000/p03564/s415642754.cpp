#include<stdio.h>
int main (){
	int Na;
	int Ka;
	int hasil = 1;
	
	scanf("%d", &Na);
	scanf("%d", &Ka);
	
	for(int i = 1;i<=Na;i++){
		if(hasil<Ka){
			hasil*=2;
		}else{
			hasil=hasil+Ka;
		}
	}
	printf("%d", hasil);
	return 0;
}