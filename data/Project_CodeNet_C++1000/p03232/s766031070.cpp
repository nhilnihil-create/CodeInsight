#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
const int MOD = 1e9+7;
int n;
ll d, a, b, x, y, c, ac[MX], ans;
ll exgcd(ll a, ll b, ll &x, ll &y){
	if(b){
		exgcd(b, a%b, y, x);
		y = (y - a/b*x%MOD + MOD) % MOD;
	}else{
		x = 1; y = 0;
	}
	return x;
}
int main(){
	scanf("%d", &n);
	rep(i,n) ac[i+1] = (ac[i] + exgcd(i+1,MOD,x,y)) % MOD;
	rep(i,n){
		scanf("%lld", &c);
		ans = (ans + (ac[i+1] + ac[n-i] - 1) * c) % MOD;
	}
	rep(i,n) ans = ans * (i+1) % MOD;
	printf("%lld\n", ans);
}