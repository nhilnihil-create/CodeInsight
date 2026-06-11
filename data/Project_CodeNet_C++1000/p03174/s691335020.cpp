#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
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
const int N = 3e6 + 5, inf = 1e9, mod = 1e9 + 7;
using namespace std;

int n, a[25][25];
ll dp[25][N];

ll solve(int row, int mask)
{
    if(row == n)
        return 1;
    if(dp[row][mask] != -1)
        return dp[row][mask];
    ll ret = 0;
    for(int col = 0; col < n; col++)
    {
        if(a[row][col] && !((1 << col) & mask))
            ret = (ret + solve(row + 1, mask | (1 << col))) % mod;
    }
    return dp[row][mask] = ret;
}

int main()
{
    IO
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << solve(0, 0) << '\n';
    return 0;
}