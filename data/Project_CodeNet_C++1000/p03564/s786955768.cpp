#include<stdio.h>

int main(){
	int n,add;
	int angka=1;
	scanf("%d%d",&n,&add);
	for(int i = 1;i<=n;i++){
		if(angka<=add) angka*=2;
		else angka+=add;
	}
	printf("%d\n",angka);
	
	
	
	return 0;
}