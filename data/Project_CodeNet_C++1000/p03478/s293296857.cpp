#include<stdio.h>
int main(){
	int a, b, c;
	int d=0;
	scanf("%d %d %d", &a, &b, &c);
	for(int i=1; i<=a; i++){
		int x=i;
		int ttl=0;
		while(x>0){
			ttl+=x%10;
			x/=10;
		}
		if(ttl>=b && ttl<=c){
			d+=i;
		}
	}
	printf("%d", d);
	return 0;
}