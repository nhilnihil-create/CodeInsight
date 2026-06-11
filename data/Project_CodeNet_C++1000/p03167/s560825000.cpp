#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define c(a,n) for(size_t i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(size_t i = 0; i < n; i++)
#define asort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.begin(), a.end(), greater<int>())
 
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef unordered_map<string,int> umsi;

const int M = 1e9 + 7;

int32_t main()
{
    fast_io;                        
    int h, w;
    cin >> h >> w;
    char c;
    vector<vector<char>> grid(h+1, vector<char>(w+1));
    vii dp(h+1, vi(w+1));
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            cin >> grid[i][j];
    
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(grid[i][j] == '.')
            {
                if(i == 1)
                {
                    if(j == 1)
                        dp[i][j] = 1;
                    if(j > 1 && dp[i][j-1])
                        dp[i][j] = 1;
                }
                else
                {
                    if(dp[i-1][j] == 0 && dp[i][j-1] == 0)
                        dp[i][j] = 0;
                    else if(dp[i-1][j] == 0)
                        dp[i][j] = dp[i][j-1];
                    else if(dp[i][j-1] == 0)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = ((dp[i-1][j])%M + (dp[i][j-1])%M)%M;    
                }
            }
        }
    }
    cout << dp[h][w]%M;


    return 0;
}