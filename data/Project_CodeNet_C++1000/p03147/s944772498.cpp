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
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int h[110];
    rep(i, N) cin >> h[i];
    int ans = 0;
    rep(i, N) ans += h[i];
    rep(i, N - 1) {
        int c = min(h[i], h[i + 1]);
        ans -= min(h[i], h[i + 1]);
        // h[i] -= c;
        // h[i + 1] -= c;
    }
    cout << ans << endl;


    return 0;
}
