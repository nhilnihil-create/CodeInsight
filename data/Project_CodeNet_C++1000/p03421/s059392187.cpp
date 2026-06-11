#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	if(a+b>n+1||a*b<n){
		puts("-1");
		return 0;
	}
	while(n){
		long long tmp=min(a,n-b+1);
		for(long long i=n-tmp+1;i<=n;i++)
			printf("%lld ",i);
		n-=tmp;
		b--;
	}
	return 0;
} 