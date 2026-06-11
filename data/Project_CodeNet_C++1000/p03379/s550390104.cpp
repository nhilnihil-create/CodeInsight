#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    vector<ll> AS = A; sort(all(AS));
    ll L = AS[n/2-1], R=AS[n/2];
    
    vector<ll> res;
    rep(i, n){
        ll tmp = A[i];
        if(tmp <= L)res.push_back(R);
        else res.push_back(L);
    }
    rep(i, n){
        cout << res[i] << ln;
    }
}
