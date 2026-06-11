#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000000000
#define fr first
#define sc second
using vl =vector<ll>;
using vvl =vector<vl>;
const ll md = 998244353;
vl pr(2e3+1, true);

ll ad(ll a, ll b, ll mod = md) {
    return (a%mod + b%mod + mod) % mod;
}

ll ml(ll a, ll b, ll mod = md) {
    return ( (a%mod) * (b%mod) ) % mod;
}

ll pw(ll x, ll n, ll mod = md) {
    ll res = 1;
    x %= mod;
    while (n) {
        if (n & 1)  res = (res*x)%mod;
        n = (n >> 1);
        x = (x*x)%mod;
    }
    return res;
}

ll log(ll b, ll e) {
	ll i, x = b;
	for(i = 0; x <= e; i++, x *= b) {}
	return i;
}

// ll dp[19][163][1460][2];
// string s;

// ll call(int idx, int sum, int sqr, int edge) {
// 	if(idx == n) {
// 		if(pr[sum] && pr[sqr]) return 1;
// 		else return 0;
// 	}
// 	ll &ans = dp[idx][sum][sqr][edge];
// 	if(ans != -1) return ans;
// 	ans = 0;
// 	for(int i = 0; i <= (tight ? s[i] - '0' : 9); ++i) {
// 		ans += call(idx + 1, sum + i, sqr + i*i, edge || i == s[i] - '0');
// 	}
// 	return ans;
// }

void sieve(ll n) {
    for(int i = 2; i*i <= n; i++) {
        if(pr[i]) {
            for(int j = i*i; j <= n; j += i) {
                pr[j] = false;
            }
        }
    }
}

ll dp[100001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; ++i) {
    	int x = s[i-1] - '0';
    	dp[i][0] = dp[i-1][1] + (x==1);
    	dp[i][1] = dp[i-1][0] + (x==0);
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
    return 0;
}