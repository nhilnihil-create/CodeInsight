#include <stdio.h>
int main(){
	int n,a,b;
	long long int total=0;
	scanf("%d %d %d", &n, &a, &b);
	
	int i1=0,i2=0, i3=0, i4=0, i5=0;
	for(int i=1;i<=n;i++){
//		
//		i1=i/10000;	
//		i2=i/1000;
//		i3=(i%1000)/100;
//		i4=(i%100)/10;
//		i5=i%10;
		int temp=i;
		int sum=0;
		while(temp!=0){
			sum+= temp%10;
			temp/=10;
		}

		if(sum >=a && sum<=b){
			total+=i;
		
		}
	}

		printf("%lld\n", total);


	
	return 0;
}