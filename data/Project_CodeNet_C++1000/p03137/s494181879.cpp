#include <bits/stdc++.h>
#define INF 1e9
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
    int N,M;
    cin >> N >> M;
    vector<int> vp(M);
    if (N >= M ) {
        cout << 0 << endl;
        return;
    }
    REP(i,M) {
        int x;
        cin >> x;
        vp[i] = x;
    }
    sort(ALL(vp));
    vector<int> vl(M-1);
    REP(i,M-1) vl[i] = vp[i+ 1] - vp[i];
    sort(ALL(vl));
    reverse(ALL(vl));
    ll sm = 0;
    FOR(i,N-1,M-1) sm += vl[i];
    cout << sm << endl;
}

int main() {
    solve();
    return 0;
}
