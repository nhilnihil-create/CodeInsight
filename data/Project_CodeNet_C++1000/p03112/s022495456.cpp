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
#define INF2 1000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<int> v1, v2;
    v1.push_back(-INF2);
    v2.push_back(-INF2);
    rep(i, A) {
        int e; cin >> e;
        v1.push_back(e);
    }
    rep(i, B) {
        int e; cin >> e;
        v2.push_back(e);
    }
    v1.push_back(INF2);
    v2.push_back(INF2);

    while(Q--) {
        int x; cin >> x;
        int l1, r1, l2, r2;
        l1 = *(--upper_bound(v1.begin(), v1.end(), x));
        r1 = *(lower_bound(v1.begin(), v1.end(), x));
        l2 = *(--upper_bound(v2.begin(), v2.end(), x));
        r2 = *(lower_bound(v2.begin(), v2.end(), x));
        //cout << "*" << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
        int ans = INF2;
        ans = min(ans, x - min(l1, l2));
        ans = min(ans, max(r1, r2) - x);
        ans = min(ans, x - l1 + r2 - l1);
        ans = min(ans, r2 - x + r2 - l1);
        ans = min(ans, x - l2 + r1 - l2);
        ans = min(ans, r1 - x + r1 - l2);
        cout << ans << endl;
    }


    return 0;
}
