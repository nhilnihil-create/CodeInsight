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
#define int long long
map<int, int> mp;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[200010];
    rep(i, n) cin >> a[i];
    sort(a, a + n, greater<int>());
    rep(i, n) mp[a[i]]++;
    int ans = 0;
    rep(i, n) {
        int k1 = a[i];
        if(mp[k1] == 0) continue;
        mp[k1]--;
        int times = (1LL << 30);
        while(times >= 1) {
            int k2 = times - a[i];
            if(k2 >= 0)
            //cout << k1 << " " << k2 << " " << k1 + k2 << " " << times << endl;
            if(mp[k2] > 0) {
                ans++;
                mp[k2]--;
                //cout << "*" << k1 << " " << k2 << " " << k1 + k2 << " " << times << endl;
                break;
                
            }
            times >>= 1;
        }
    }
    cout << ans << endl;

    return 0;
}
