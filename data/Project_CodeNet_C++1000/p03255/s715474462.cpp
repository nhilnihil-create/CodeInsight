#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long a[200010];
unsigned long long s[200010];
long long x;
int n;
int main(){
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	unsigned long long ans=10000000000000000ull;
	for(int k=1;k<=n;++k){
		unsigned long long now=0;
		unsigned long long mul=3;
		for(int i=n;i>0;i-=k){
			now+=(s[i]-s[max(0,i-k)])*max(5ull,mul);
			mul+=2ull;
			if(now>ans)break;
		}
		ans=min(ans,now+(k+n)*x);
	}
	cout<<ans;
	return 0;
}