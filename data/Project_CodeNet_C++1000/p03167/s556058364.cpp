#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int row,col,dp[2][10005];
char grid[10005][10005];

void addSelf(int &x,int y)
{
    x += y;
    if(x >= mod)
        x -= mod;
}

void FuN()
{
    for(int i=1 ; i<=row ; i++){

        for(int j=1 ; j<=col ; j++)
            dp[i & 1][j] = 0;

        for(int j=1 ; j<=col ; j++){
            if(grid[i][j] == '#'){
                dp[i & 1][j] = 0;
                continue;
            }
            if(i == 1 && j == 1)
                dp[i & 1][j] = 1;
            else{
                addSelf(dp[i & 1][j] , dp[(i-1) & 1][j]);
                addSelf(dp[i & 1][j] , dp[i & 1][j-1]);
            }
        }
    }
    cout<<dp[row & 1][col]<<endl;
}

int main()
{
    cin>>row>>col;
    for(int i=1 ; i<=row ; i++){
        for(int j=1 ; j<=col ; j++)
            cin>>grid[i][j];
    }
    FuN();
    return 0;
}
