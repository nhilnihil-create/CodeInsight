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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[100010], b[100010];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int exceed = 0, lack = 0;
    vector<int> v;
    int ans1 = 0;
    rep(i, n) {
        if(a[i] > b[i]) {
            exceed += a[i] - b[i];
            v.push_back(a[i] - b[i]);
        }
        else if(a[i] < b[i]) {
            lack += b[i] - a[i];
            ans1++;
        }
    }
    if(lack > exceed) {cout << -1 << endl; return 0;}
    int ans2 = 0;
    sort(v.begin(), v.end(), greater<int>());
    while(lack > 0) {
        lack -= v[ans2++];
    }
    cout << ans1 + ans2 << endl;
    


    return 0;
}
