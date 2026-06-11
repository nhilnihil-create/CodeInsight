#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 10000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<int> s, t;
    s.push_back(-INF2); s.push_back(-INF2);
    rep(i, A) {
        int e; cin >> e;
        s.push_back(e);
    }
    s.push_back(INF2); s.push_back(INF2);
    t.push_back(-INF2); t.push_back(-INF2);
    rep(i, B) {
        int e; cin >> e;
        t.push_back(e);
    }
    t.push_back(INF2); t.push_back(INF2);

    while(Q--) {
        int x; cin >> x;
        auto itr1 = lower_bound(s.begin(), s.end(), x);
        auto itr2 = lower_bound(t.begin(), t.end(), x);
        int ans = INF2;
        REP(i, -1, 1) {
            REP(j, -1, 1) {
                int x1 = *(itr1 + i);
                int x2 = *(itr2 + j);
                ans = min(ans, abs(x - x1) + abs(x1 - x2));
                ans = min(ans, abs(x - x2) + abs(x2 - x1));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
