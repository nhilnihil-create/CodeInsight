#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
#define int int64
// 赤と青の数は決め打ちできる
// e.g.)
// 5
// a + 2b = 5(k)
// a + b <= 4(sm)
// = 3
// (a,b) = (1,2)
// (1,0,2) 4C1*3C1
// (0,1,1) 4C1*3C1
// = 4
// (a,b) = (3,1)
// (3,0,1) 4C1
// (2,1,0) 4C1*3C1

int MOD = 998244353;
constexpr int MAX_N = 303030;

int fact[MAX_N];
int ifact[MAX_N];
 
int power(int x, int n) {
	int res = 1LL;
	while (n > 0) {
		if (n & 1) (res *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return res % MOD;
}
 
int inv(int x) {
	return power(x, MOD - 2);
}
 
int nCr(int n, int r) {
	if (n < 0 || r < 0 || r > n) return 0;
	if (r > n / 2) r = n - r;
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

signed main(){
  int n,a,b,k;cin>>n>>a>>b>>k;
	fact[0] = ifact[0] = 1;
	for(int i=1;i<MAX_N;++i) {
		(fact[i] = fact[i - 1] * i) %= MOD;
		ifact[i] = inv(fact[i]);
	}

  int ans = 0;
  for(int aa=0;aa<=n;++aa){
    int bb = (k-aa*a)/b;
    if((k-aa*a)%b!=0) continue;
    if(!(aa>=0&&bb>=0)) continue;

    int res = nCr(n,aa) % MOD;
    (res *= nCr(n,bb)) %= MOD;
    // cerr << res << endl;
    (ans += res) %= MOD;
  }
   
  cout<<ans<<endl;
  
  return 0;
}