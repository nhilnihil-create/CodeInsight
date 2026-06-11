#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; i++) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i*i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x;}
    vector<int> factorList(int x) {
        vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<P> factor(int x) {
        vector<int> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<P> res(1, P(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
    vector<pair<ll,int>> factor(ll x) {
        vector<pair<ll,int>> res;
        for (int p : primes) {
            int y = 0;
            while (x%p == 0) x /= p, ++y;
            if (y != 0) res.emplace_back(p,y);
        }
        if (x != 1) res.emplace_back(x,1);
        return res;
    }
};

vector<int> d;
map<int,int> mp;
int ans = 0;

int dp[30][80];

int main() {
    int n;
    cin >> n;
    Sieve sieve(n);
    for (int i = 1; i <= n; i++) {
        vector<P> a = sieve.factor(i);
        for (auto p : a) {
            mp[p.first] += p.second;
        }
    }
    d = sieve.primes;
    
    rep(i,30)rep(j,80) dp[i][j] = 0;
    dp[0][1] = 1;
    rep(i,d.size()) {
        for (int j = 1; j <= 75; j++) {
            if (dp[i][j] == 0) continue;
            int x = mp[d[i]];
            for (int k = 0; k <= x; k++) {
                if (j*(k+1) > 75) break;
                dp[i+1][j*(k+1)] += dp[i][j];
            }
        }
    }
    cout << dp[d.size()][75] << endl;
    return 0;
}