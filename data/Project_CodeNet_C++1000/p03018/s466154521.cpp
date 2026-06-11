#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int main() {
    string s;
    cin >> s;
    
    ll ans = 0, cur = 0;
    
    REP(i, s.size()) {
        if (s[i] == 'A') ++cur;
        else if (s.substr(i, 2) == "BC") { ans += cur; ++i; }
        else cur = 0;
    }
    
    cout << ans << endl;
    
    return 0;
}
