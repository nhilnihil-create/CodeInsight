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
const int MX = 505;
int a[MX][MX];
int ans[MX][MX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    int n,m,Q; cin >> n >> m >> Q;
    FOR(i,1,m) {
        int l,r; cin >> l >> r;
        a[l][r]++;
    }
    FOR(i,1,n) {
        FOR(j,2,n) {
            a[i][j] += a[i][j-1];
        }
    }
    FOR(i,1,n) {
        for(int j=n-1; j>=1; j--) {
            a[j][i] += a[j+1][i];
        }
    }
    while(Q--) {
        int p,q; cin >> p >> q;
        cout << a[p][q] << endl;
    }
    return 0;
}
