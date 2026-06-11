#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
typedef pair<int, int> P;

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    P p[100010];
    rep(i, n) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    int ans = 0;
    int i = 0;
    while(m > 0) {
        int c = min(m, p[i].second);
        m -= c;
        ans += p[i].first * c;
        i++;
    }
    cout << ans << endl;


    return 0;
}
