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
    map<int,int> mp;
    int N;
    cin >> N;
    REP(_,N) {
        int D;
        cin >> D;
        if(mp.count(D) == 0) mp[D] = 0;
        mp[D]++;
    }

    int M;
    cin >> M;
    REP(_,M) {
        int T;
        cin >> T;
        if (mp.count(T) == 0) {
            cout << "NO" << endl;
            return;
        }
        if (mp[T] == 0) {
            cout << "NO" << endl;
            return;
        }
        mp[T]--;
    }
    cout << "YES" << endl;

}

int main() {
    solve();
    return 0;
}