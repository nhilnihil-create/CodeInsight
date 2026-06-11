#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[1<<22][22];
int a[22][22];
int N=0;
ll mod=1000000007;

void solve(int n, int m)
{
    if(dp[n][m]!=-1)
        return;
    dp[n][m]=0;
   
    if(m==N-1)
    {
        for(int i=0; i<N; i++)
        {

            if( a[m][i]==1 && (n&(1<<i))==(1<<i))
            {
                dp[n][m]=1;
                dp[n][m]%=mod;
                return;
            }
        }
    }

    for(int i=0; i<N; i++)
    {

        if( a[m][i]==1 && (n&(1<<i))==(1<<i))
        {
            solve(n^(1<<i), m+1);
            dp[n][m]+=dp[n^(1<<i)][m+1];
            dp[n][m]%=mod;
        }
    }

}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> a[i][j];

        }
    }
    for(int i=0; i < (1<<N); i++)
    {
        for(int j=0; j<N; j++)
        {
            dp[i][j]=-1;
        }
    }


    solve( (1<<N) - 1, 0);
    cout << dp[ (1<<N) -1][0];
    
}