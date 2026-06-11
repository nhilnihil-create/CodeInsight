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
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<int> A[3];
    rep(i, X) { int a; cin >> a; A[0].push_back(a);}
    rep(i, Y) { int a; cin >> a; A[1].push_back(a);}
    rep(i, Z) { int a; cin >> a; A[2].push_back(a);}
    rep(i, 3) sort(A[i].begin(), A[i].end(), greater<int>());
    vector<int> v1, v2;
    rep(i, X) {
        rep(j, Y) {
            v1.push_back(A[0][i] + A[1][j]);
        }
    }
    sort(v1.begin(), v1.end(), greater<int>());
    rep(i, min((int)v1.size(), K)) {
        rep(j, Z) {
            v2.push_back(v1[i] + A[2][j]);
        }
    }
    sort(v2.begin(), v2.end(), greater<int>());
    rep(i, K) cout << v2[i] << endl;





    return 0;
}
// 8 6 5 4 3 1