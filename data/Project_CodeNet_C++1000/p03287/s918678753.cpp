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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a[100010];
    rep(i, n) cin >> a[i];
    int sum[100010] = {};
    rep(i, n) sum[i + 1] = (sum[i] + a[i]) % m;
    // rep(i, n) cout << sum[i + 1] << " ";
    // cout << endl;
    map<int, int> mp;
    rep(i, n) mp[sum[i + 1]]++;
    int ans = 0;
    rep(i, n) {
        if(sum[i + 1] == 0) ans++;
        ans += mp[sum[i + 1]] - 1;
    
        mp[sum[i + 1]]--;
        
    }
    cout << ans << endl;

    return 0;
}
// 0 1 1
// 0 1 0