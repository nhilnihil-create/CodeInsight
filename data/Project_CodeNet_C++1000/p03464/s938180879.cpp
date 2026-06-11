#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;
	scanf("%d",&k);
	long long arr[k];
	for(int i=0;i<k;i++){
		scanf("%lld",&arr[i]);
	}
	if(arr[k-1]!=2){printf("-1");return 0;}
	long long mi=2,ma=3;
	for(int i=k-2;i>=0;i--){
		mi=ceil((double)(mi)/(double)(arr[i]))*arr[i];
		ma/=arr[i];ma*=arr[i];ma+=arr[i]-1;
	}
	if(mi>ma)printf("-1");
	else printf("%lld %lld",mi,ma);
}