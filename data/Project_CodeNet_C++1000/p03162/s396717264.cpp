#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7;

void solve()
{   
    int n; cin >> n;
    vector<int> a, b, c;
    for(int i = 0; i < n; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        a.pb(x);
        b.pb(y);
        c.pb(z);
    }

    int dp[n][3];
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}

int main()
{
    fastio

    //ifstream fin(".in");
    //ofstream fout(".out");


    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
