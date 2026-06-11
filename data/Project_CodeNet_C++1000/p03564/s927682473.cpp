#include <bits/stdc++.h>
#define INF 1e9
#define INFLL 1ull<<60u
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    unsigned int N,K;
    cin >> N >> K;
    ll ans = INFLL;
    for(unsigned int bit = 0; bit < (1u << K); bit++) {
        ll state = 1;
        REP(i,N) {
            if(bit & (1u << i)) state *= 2;
            else state += K;
        }
        chmin(ans,state);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}