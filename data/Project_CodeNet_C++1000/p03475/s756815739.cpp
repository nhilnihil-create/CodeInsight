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

struct Data {
    int C,S,F;
};

void solve() {
    int N;
    cin >> N;
    vector<Data> vd(N-1);
    REP(i,N-1) {
        int C,S,F; cin >> C >> S >> F;
        vd[i] = Data{C,S,F};
    }

    vector<int> ans(N,0);
    REP(i,N-1) {
        FOR(j,0,i+1) {
            // まだ運行されていないならSiまで待ってそれに乗る
            auto p1 = vd[i].S + vd[i].C;
            auto p2 = ((ans[j]+vd[i].F-1)/vd[i].F)*vd[i].F + vd[i].C;
            if (ans[j] < vd[i].S) ans[j] = p1;
            else ans[j] = p2;
        }
    }
    REP(i,N) cout << ans[i] << endl;
}

int main() {
    solve();
    return 0;
}