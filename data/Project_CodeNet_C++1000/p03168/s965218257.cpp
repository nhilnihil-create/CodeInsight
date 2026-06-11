#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <complex>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const int N = 3e3 + 5, inf = 1e9, mod = 1e9 + 7;
using namespace std;
int n;
ld arr[N], ans = 0.0, dp[N][N] = {};

ld solve(int pos, int h)
{
    if(pos == n)
        return (h > n / 2);
    if(dp[pos][h] != -1)
        return dp[pos][h];
    return dp[pos][h] = (solve(pos + 1, h + 1) * arr[pos]) + (solve(pos + 1, h) * (1.0 - arr[pos]));
}

int main()
{
    IO
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dp[i][j] = -1.0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << fixed << setprecision(10) << solve(0, 0) << '\n';
    return 0;
}