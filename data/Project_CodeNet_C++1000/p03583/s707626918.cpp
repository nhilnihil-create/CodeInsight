#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(ll i=(n); i >= 0; --i)
#define FOR(i, m, n) for(ll i = (m); i < (n); ++i)
#define REP(i, n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    ll N;
    cin >> N;
    FOR(n,1,3501) FOR(h,1,3501) {
        ll child = h*n*N;
        ll mother = 4 * h * n - N * n - N*h;
        if(mother == 0) continue;
        if (child % mother != 0) continue;
        auto w = child / mother;
        if ( w > 0) {
            cout << h << " " << n << " " << w << endl;
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}