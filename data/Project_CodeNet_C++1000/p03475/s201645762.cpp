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
    int n; cin >> n;
    vector<ll> C(n-1), S(n-1), F(n-1);
    rep(i, n-1) cin >> C[i] >> S[i] >> F[i];

    vector<ll> ans(n);
    rep(i, n){
        ll time = 0, p = i;
        while(p < n-1){
            if(S[p] >= time) time = S[p];
            else if(time%F[p] != 0) time += (F[p]-(time%F[p]));
            time += C[p];
            p++;
        }
        ans[i] = time;
    }
    rep(i, n){
        cout << ans[i] << ln;
    }
}