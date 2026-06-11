#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	int m,k;
	scanf("%d %d",&m,&k);
	int sum = 0;
	for(int i=0;i<(1<<m);i++)if(i!=k)sum^=k;
	if(k==0){
		for(int i=0;i<(1<<m);i++)printf("%d %d ",i,i);
		printf("\n");
		return 0;
	}
	if(m==1){
		if(k>=1)puts("-1");
		else puts("0 0 1 1");
		return 0;
	}
	if((1<<m)<=k)return puts("-1")*0;
	printf("%d ",k);
	for(int i=0;i<(1<<m);i++)if(i!=k)printf("%d ",i);
	printf("%d ",k);
	for(int i=(1<<m)-1;i>=0;i--)if(i!=k)printf("%d ",i); 
}