#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){ 
    int n; cin >> n;
    map<int, int> sisuu;
    rept(i, 1, n+1){
        vector<pll> tmp = prime_factorize(i);
        for(auto p: tmp){
            sisuu[p.first] += p.second;
        }
    }
    map<int, int>cnt;
    for(auto s: sisuu){
        int num = s.second;
        if(num>=74) cnt[75]++;
        if(num>=24) cnt[25]++;
        if(num>=14) cnt[15]++;
        if(num>=4) cnt[5]++;
        if(num>=2) cnt[3]++;
    }

    ll res = 0;
    res += cnt[75];
    res += cnt[25] * (cnt[3]-1);
    res += cnt[15] * (cnt[5]-1);
    res += cnt[5]*(cnt[5]-1)/2 * (cnt[3]-2);

    cout << res << ln;
} 