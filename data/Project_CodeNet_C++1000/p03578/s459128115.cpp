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
    int N; cin >> N;
    map<int,int> mp;
    REP(_,N) {
        int d; cin >> d;
        if(!mp.count(d)) mp[d] = 0;
        mp[d]++;
    }
    int M; cin >> M;
    REP(_,M) {
        int t; cin >> t;
        if (mp.count(t) && mp[t]) mp[t]--;
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    solve();
    return 0;
}