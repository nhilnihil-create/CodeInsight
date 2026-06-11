#include<iostream>
#include<vector>
using namespace std;
int num=10e8+7;
int H,W;
bool inside(int x,int y)
{
    if(x>=0&&x<=H-1&&y>=0&&y<=W-1)
    return true;
    else
    {
        return false;
    }
}
int main()
{
    cin>>H>>W;
    vector<vector<int>> dp(H+1,vector<int> (W+1,0));
    vector<string> grid;
    for(int i=0;i<H;i++)
    {
        string s;
        cin>>s;
        grid.push_back(s);
    }
    if(grid[0][0]=='.')
    dp[0][0]=1;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(inside(i,j-1)&&grid[i][j]=='.')
            {
                dp[i][j]+=dp[i][j-1];
            }
            if(inside(i-1,j)&&grid[i][j]=='.')
            {
                dp[i][j]+=dp[i-1][j];
            }
            dp[i][j]%=num;
        }
    }
    cout<<dp[H-1][W-1];
}