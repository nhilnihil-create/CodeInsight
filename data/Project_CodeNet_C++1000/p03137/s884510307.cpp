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
    int N, M;
    cin >> N >> M;
    int X[100010];
    rep(i, M) cin >> X[i];
    sort(X, X + M);
    int ans = 0;
    vector<int> v;
    rep(i, M-  1) v.push_back(X[i + 1] - X[i]);
    sort(v.begin(), v.end());
    rep(i, M - N) {
        ans += v[i];
        //cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
