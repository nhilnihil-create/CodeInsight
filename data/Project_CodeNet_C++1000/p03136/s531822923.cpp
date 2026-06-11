#include<stdio.h>
int main(){
	int n,x,b=0,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(b<x) b=x;
		sum+=x;
	}
	if(2*b<sum) printf("Yes");
	else printf("No");
	return 0;
}