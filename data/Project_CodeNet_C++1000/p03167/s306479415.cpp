#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int r,c;
vector<vector<char>> grid;
vector<vector<ll>> dp;

void print()
{
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

inline bool is_safe(int i, int j)
{
    return (i>=1 && j>=1 && i<=r && j<=c && grid[i][j]!='#');
}

void init()
{
    grid.resize(r+1, vector<char>(c+1));
    dp.resize(r+1, vector<ll>(c+1));
}

void solve()
{
    for(int i=1; i<=c; i++) {
        if(is_safe(1, i)) 
            dp[1][i] = 1;
        else break;
    }
    for(int j=1; j<=r; j++) {
        if(is_safe(j, 1))
            dp[j][1] = 1;
        else break;
    }
    for(int i=2; i<=r; i++){
        for(int j=2; j<=c; j++){
            if(is_safe(i, j)){
                if(is_safe(i-1, j)) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                if(is_safe(i, j-1)) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    }
    cout << dp[r][c] << '\n';
}

int main()
{
    cin >> r >> c;
    init();
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> grid[i][j];
        }
    }

    solve();
    return 0;
}