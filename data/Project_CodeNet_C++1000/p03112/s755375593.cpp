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
const int MX = 1e5+7;
ll s[MX];
ll t[MX];
int A,B,Q;

int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    cin >> A >> B >> Q;
    s[0] = -LINF;
    s[A+1] = LINF;
    t[0] = -LINF;
    t[B+1] = LINF;
    FOR(i,1,A) {
        cin >> s[i];
    }
    FOR(i,1,B) {
        cin >> t[i];
    }
    A += 2;
    B += 2;
    while(Q--) {
        ll x; cin >> x;
        ll su, sd, tu, td;
        ll ans = LINF;
        su = *lower_bound(s, s+A, x)-x;
        sd = x - *(upper_bound(s, s+A, x)-1);
        tu = *lower_bound(t, t+B, x)-x; 
        td = x - *(upper_bound(t, t+B, x)-1);
        chmin(ans, max(su, tu));
        chmin(ans, max(sd, td));
        chmin(ans, min(su,td)+su+td);
        chmin(ans, min(sd, tu)+sd+tu);
        cout << ans  << endl;
    }
    return 0;
}
