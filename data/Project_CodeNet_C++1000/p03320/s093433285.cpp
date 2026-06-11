#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double calc(ll x){
	ll y=10,len=1,sum=0,res=x;
	while (y<=x) y*=10,len++;
	while (len--){
		y/=10;
		sum+=x/y;
		x%=y;
	}
	return res*1.0/sum*1.0;
}
bool ck(ll a){
	ll now=1;
	while (now<=a){
		if (calc(now+a)<calc(a)) return 0;
		now*=10;
	}
	return 1;
}
int main(){
	int k;
	scanf("%d",&k); 
	ll now=0;
	while (k--){
		ll a=1;
		while (1){
			if (ck(now+a)){now+=a; break;}
			a*=10;
		}
		printf("%lld\n",now);
	}
	return 0;
}