#include <bits/stdc++.h>
#define MOD 1000000007
//for(int i=0; i<n; ++i)
using namespace std;
#define all(c) c.begin(), c.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define ll long long

vector<vector<vector<double>>> dp(301, vector<vector<double>>(301, vector<double>(301, -1)));

double steps(int x, int y, int z, int n)
{
    if (x == 0 && y == 0 && z == 0)
        return 0;
    if (x < 0 || y < 0 || z < 0)
        return 0;
    if (dp[x][y][z] != -1)
        return dp[x][y][z];

    double p0 = (n - x - y - z) / (n * 1.0),
           p1 = (x) / (n * 1.0),
           p2 = (y) / (n * 1.0),
           p3 = (z) / (n * 1.0);

    double sol = (1.0 + p1 * steps(x - 1, y, z, n) + p2 * steps(x + 1, y - 1, z, n) + p3 * steps(x, y + 1, z - 1, n)) / (1.0 - p0);
    //cout << "(" << x << ", " << y << ", " << z << ")" << sol << endl;
    dp[x][y][z] = sol;
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x = 0, y = 0, z = 0, t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        if (t == 1)
            ++x;
        if (t == 2)
            ++y;
        if (t == 3)
            ++z;
    }
    cout << setprecision(10) << steps(x, y, z, n) << endl;
    return 0;
}