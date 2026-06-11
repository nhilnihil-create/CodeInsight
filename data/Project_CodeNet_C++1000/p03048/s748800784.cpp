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
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int cnt = 0;
    REP(r,3001) REP(g,3001) {
        int rest_balls = N - ((R*r) + (g*G));
        if (rest_balls < 0) continue;
        if (rest_balls%B == 0) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    solve();
    return 0;
}