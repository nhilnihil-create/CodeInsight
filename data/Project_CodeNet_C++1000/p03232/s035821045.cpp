#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
using namespace std;
const int N=1e5+5,mod=1e9+7;
int n,w,ans,inv[N],fac;
int main(){
	scanf("%d",&n);
	inv[1]=1; rep (i,2,n) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	rep (i,1,n) inv[i]=(inv[i]+inv[i-1])%mod; fac=1;
	rep (i,1,n){
		scanf("%d",&w);
		ans=(ans+(ll)(inv[i]+inv[n-i+1]-1)%mod*w%mod)%mod;
		fac=(ll)fac*i%mod;
	}
	printf("%d\n",(ll)ans*fac%mod);
	return 0;
}