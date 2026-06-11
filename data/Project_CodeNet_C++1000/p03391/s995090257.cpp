#include<bits/stdc++.h>
using namespace std;
int T;
long long sum,a,b,Min=1e9,flag;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&a,&b);
		sum+=b;
		if(b<a&&Min>b)Min=b;
		if(b!=a)flag=1;
	}
	if(flag==1)printf("%lld",sum-Min);
	else puts("0");
}
