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
typedef pair<int, int> P;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    map<P, int> mp;
    P c1[100010], c2[100010];
    rep(i, m) {
        cin >> c1[i].first >> c1[i].second;
        c2[i] = c1[i];
    }
    sort(c2, c2 + m);
    int k = 1;
    rep(i, m) {
        if(i > 0 && c2[i].first != c2[i - 1].first) k = 1;
        mp[c2[i]] = k++;
    }
    rep(i, m) {
        cout << setfill('0') << right << setw(6) << c1[i].first; 
        cout << setfill('0') << right << setw(6) << mp[c1[i]] << endl;
    }


    return 0;
}
