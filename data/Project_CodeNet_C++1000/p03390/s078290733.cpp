#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		ll a,b,ans=0;
		scanf("%lld%lld",&a,&b);
		ll x=sqrt(a*b);
		if(x*(x+1)<a*b)ans=2*x-1;
		else if(x*x==a*b){
			if(a==b)ans=(x-1)*2;
			else ans=(x-1)*2-1;
		}
		else ans=(x-1)*2;
		printf("%lld\n",ans);
	}
	return 0;
} 