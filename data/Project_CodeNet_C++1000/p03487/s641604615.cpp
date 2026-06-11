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
    int ans = 0;
    int n; cin >> n;
    int cnt[100010] = {};
    rep(i, n) {
        int a; cin >> a;
        if(a > 100000) {
            ans++;
            continue;
        }
        cnt[a]++;
    }
    REP(i, 1, 100000) {
        if(cnt[i] == 0) continue;
        if(cnt[i] < i) ans += cnt[i];
        if(cnt[i] > i) ans += cnt[i] - i;
    }
    cout << ans << endl;

    return 0;
}
