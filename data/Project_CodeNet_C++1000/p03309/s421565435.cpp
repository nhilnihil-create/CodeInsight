#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#include <tuple>
#include <cassert>
#include <array>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ti = tuple<int, int, int>;

#define REP(i,m,n) for(int i=(m); i<(n); i++)
#define RREP(i,n,m) for(int i=(n);i>=(m); i--)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << x << endl
// #define int long long 

const double eps=1e-14;
const int mod = 1e9 + 7;
const int inf = ((1<<30)-1);
const ll linf = (1LL<<60);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    REP(i,0,n) cin >> a[i];
    REP(i,0,n) a[i] -= i+1;
    sort(a,a+n);
    int b = a[(n+1)/2-1];
    ll ans = 0;
    REP(i,0,n) ans += abs(a[i]-b);
    cout << ans << endl;
    return 0;
}
