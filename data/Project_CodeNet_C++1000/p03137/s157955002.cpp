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
    int n, m;
    cin >> n >> m;
    int X[100010];
    rep(i, m) cin >> X[i];
    sort(X, X + m);
    vector<int> v;
    int sum = 0;
    rep(i, m - 1) {
        v.push_back(X[i + 1] - X[i]);
        sum += X[i + 1] - X[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    rep(i, min((int)v.size(), n - 1)) sum -= v[i];
    cout << sum << endl;

    return 0;
}
