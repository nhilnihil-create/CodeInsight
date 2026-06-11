#include <iostream>
using namespace std;

int mat[3][100005];
int func(int n)
{
    int dp[3][n];
    for(int j=0;j<3;j++)
    dp[j][0] = mat[j][0];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            int val=0;
            for(int k=0;k<3;k++)
            {
                if(k != j)
                val=max(val , dp[k][i-1]);
            }

            dp[j][i] = val + mat[j][i];
        }
    }
    int ans=0;
    
    for(int j=0;j<3;j++)
    ans=max(ans , dp[j][n-1]);

    return ans;
}

int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++) cin>>mat[j][i];
    }
    cout<<func(n);
}
