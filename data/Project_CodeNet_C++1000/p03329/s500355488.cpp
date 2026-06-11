#pragma region
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(x,arr) for(auto& x:arr)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define VPII vector<PII>
#define VPLL vector<PLL>
#define FI first 
#define SE second
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
#pragma endregion
//-------------------
const int MX = 100000+7;
int dp[MX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    int n; cin >> n;
    fill(dp+1, dp+n+1, INF);
    FOR(i,0,n-1) {
        for(int k=6; i+k<MX; k*=6) chmin(dp[i+k], dp[i] + 1);
        for(int k=9; i+k<MX; k*=9) chmin(dp[i+k], dp[i] + 1);
        chmin(dp[i+1], dp[i]+1);
    }
    cout << dp[n] << endl;
    return 0;
}
