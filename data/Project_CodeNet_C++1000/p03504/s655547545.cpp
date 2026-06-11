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

int sum[30][100010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    rep(i, N) {
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        sum[c][s]++;
        sum[c][t + 1]--;
    }
    rep(j, 30) rep(i, 100000) sum[j][i + 1] += sum[j][i];
    int ans = 0;
    rep(i, 100010) {
        int tmp = 0;
        rep(j, 30) tmp += min(1, sum[j][i]);
        ans = max(ans, tmp);
    }
    cout << ans << endl;


    return 0;
}
