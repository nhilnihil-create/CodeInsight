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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int X[200010];
    rep(i, N) cin >> X[i];
    int x[200010];
    rep(i, N) x[i] = X[i];
    sort(X, X + N);
    int midL = X[N / 2 - 1];
    int midR = X[N / 2];
    rep(i, N) {
        if(x[i] <= midL) {
            cout << midR << endl;
        } else {
            cout << midL << endl;
        }
    }

    return 0;
}
