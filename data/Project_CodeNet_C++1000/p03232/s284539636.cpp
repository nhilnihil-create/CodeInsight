#include<bits/stdc++.h>
using namespace std;
#define maxn 100020
#define rep(i,l,r) for(register int i = l ; i <= r ; i++)
#define repd(i,r,l) for(register int i = r ; i >= l ; i--)
#define rvc(i,S) for(register int i = 0 ; i < (int)S.size() ; i++)
#define rvcd(i,S) for(register int i = ((int)S.size()) - 1 ; i >= 0 ; i--)
#define fore(i,x)for (register int i = head[x] ; i ; i = e[i].next)
#define pb push_back
#define prev prev_
#define stack stack_
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pr;

typedef long long ll;
const ll mod = 1e9 + 7;
int n,a[maxn];
ll f[maxn],fac,inv[maxn];

inline ll power(ll x,ll y){
	ll res = 1;
	while ( y ){
		if ( y & 1 ) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	if ( n == 1 ){ cout<<a[1] % mod<<endl; return 0; }
	inv[1] = 1 , fac = 1;
	rep(i,2,n) inv[i] = (inv[i - 1] + power(i,mod - 2)) % mod , fac = fac * i % mod;
	ll ans = 0;
	ans = (ans + fac * inv[n] % mod * (a[1] + a[n])) % mod;
	rep(i,2,n - 1){
		ans = (ans + fac * (inv[n - i + 1] + inv[i] - 1) % mod * a[i]) % mod;
	}
	cout<<(ans % mod + mod) % mod<<endl;
}
