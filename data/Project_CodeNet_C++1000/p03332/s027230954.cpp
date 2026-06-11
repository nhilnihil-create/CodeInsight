#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 998244353;
const int N = 3e5 + 5;

int n, a, b, k, ans, fac[N], invfac[N];

int binpw(int base, int pw){
    int ans = 1;
    while(pw){
        if(pw & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        pw >>= 1;
    }
    return ans;
}

int c(int n, int k){
    int temp = fac[n] * invfac[k] % mod;
    return (temp * invfac[n - k]) % mod;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> a >> b >> k;
	fac[0] = invfac[0] = 1;
	for(int i = 1; i <= (N - 5); i++){
	    fac[i] = (fac[i - 1] * i) % mod;
	    invfac[i] = binpw(fac[i], mod - 2);
	}
	for(int i = 0; i <= n; i++){
	    int diff = k - a * i;
	    if(diff < 0 || (diff % b)) continue;
	    diff /= b;
	    if(diff > n) continue;
	    ans += c(n, i) * c(n, diff);
	    ans %= mod;
	}
	cout << ans;
}

