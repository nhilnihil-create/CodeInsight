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
#define fo(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
    int n, c; cin >> n >> c;
    vector<int> S(n), T(n), C(n);
    vector<int> plus(200010), minus(200010);
    rep(i, n){
        cin >> S[i] >> T[i] >> C[i];
        int a = (S[i]-0.5)*2, b = T[i]*2;
        plus[a]++; minus[b]++;
    }
    int mx = 0, cnt = 0;
    rep(i, 200000){
        cnt -= minus[i];
        cnt += plus[i];
        chmax(mx, cnt);
    }
    cout << min(mx, c) << ln;
}