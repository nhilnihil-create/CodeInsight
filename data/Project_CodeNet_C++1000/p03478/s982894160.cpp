#include <stdio.h>

int main(){
	int m,l,r,sum=0;
	scanf("%d %d %d", &m,&l,&r);
	for(int i=1;i<=m;i++){
		int dSum = 0;
		int temp = i;
		while (temp != 0){
			dSum = dSum + temp % 10;
			temp /= 10;
		}
		if(dSum >= l && dSum <=r){
			sum+=i;
		}
	}
	printf("%d\n", sum);
	
	return 0;
}