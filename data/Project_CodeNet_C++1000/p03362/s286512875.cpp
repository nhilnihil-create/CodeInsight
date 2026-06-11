#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

struct Sieve {
    int n;
    vector<int> f, primes;
    
    Sieve(int n=1) : n(n), f(n+1) {
        f[0] = f[1] = -1;
        for (long long i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (long long j = i*i; j <= n; j += i) {
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

    vector<pair<int, int>> factor(int x) {
        vector<int> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<pair<int, int>> res(1, pair<int, int>(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    Sieve sieve(55555);
    vi num;
    for (auto&& p : sieve.primes) {
        if (p == 2 || ((p-1)/2) % 5 == 1) num.pb(p); 
    }
    rep(i, n) {
        cout << num[i] << (i == n-1 ? "\n" : " ");
    }
}