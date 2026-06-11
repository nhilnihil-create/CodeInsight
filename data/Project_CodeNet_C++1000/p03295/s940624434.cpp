#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
    int n, m; cin >> n >> m;
    vector<pii> q(m);
    rep(i, m){
        int a, b; cin >> a >> b;
        q[i] = {b, a};
    }
    sort(all(q));

    int bef = -1, res = 0;
    rep(i, m){
        int a = q[i].second, b = q[i].first;
        if(bef < a){
            bef = b - 1; res++;
        }
    }
    cout << res << ln;
}