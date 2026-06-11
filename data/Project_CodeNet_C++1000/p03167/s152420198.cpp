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
    int h, w; cin >> h >> w;
    bool grid[h][w];
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            char x; cin >> x;
            if(x == '.') grid[i][j] = false;
            else grid[i][j] = true;
        }
    }
    ll dp[h][w];
    dp[0][0] = 1;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(i == 0 && j == 0) continue;
            if(grid[i][j]) 
            {
                dp[i][j] = 0;
                continue;
            }
            ll x = 0;
            if(i - 1 >= 0)
            {
                if(grid[i - 1][j] == 0) x += dp[i - 1][j];
                x%= MOD;
            }
            if(j - 1 >= 0)
            {
                if(grid[i][j - 1] == 0) x += dp[i][j - 1];
                x %= MOD;
            }
            dp[i][j] = x % MOD;
        }
    }
    cout << dp[h - 1][w - 1];
    
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
