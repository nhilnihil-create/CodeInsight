#include<stdio.h>

int main(){
	int i,n,add;
	int temp=1;
	scanf("%d %d", &n,&add);
	for(i=1;i<=n;i++){
		//printf("Temp awal adalah %d\n", temp);
		if(((temp*2)<=add)&&(temp<=add)){
			temp*=2;
			//printf("Temp untuk hasil perkalian adalah %d\n", temp);
		}
		else if((temp*2>=add)&&(temp<=add)){
			temp*=2;
		}
		else{
			temp+=add;
			//printf("Temp untuk hasil penjumlahan adalah %d\n", temp);
		}
	}
	printf("%d\n", temp);
	return 0;
}