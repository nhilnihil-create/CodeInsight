#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;

#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,b) for(int i=a; i<b; i++)
#define fi first
#define se second

vint primes(101);
bool is_prime[202];

void furui() {
    rep2(i, 2, 202) {
        is_prime[i] = true;
    }
    for(int i=2; i*i <= 202; i++) {
        if (is_prime[i]) {
            for(int j=i*i; j<202; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

void cnt(int n) {
    int nn = n;
    rep(i, nn+1) {
        if (is_prime[i]) {
            while(n % i == 0) {
                primes[i]++;
                n /= i;
            }
        }
    }
}

int main() {
    furui();
    int n;
    cin >> n;
    rep2(i, 1, n+1) {
        cnt(i);
    }

    vector<ll> dp(80);
    dp[1] = 1;
    rep(i, 101) {
        vector<ll> next = dp;
        rep2(j, 1, primes[i]+1) {
            rep(k, 101) {
                if (k*(j+1) < 80) {
                    next[k*(j+1)] += dp[k];
                }
            }
        }
        dp = next;
    }
    cout << dp[75] << endl;
}