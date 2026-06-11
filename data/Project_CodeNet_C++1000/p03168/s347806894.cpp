#include<iostream>
#include<vector>

#include<iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<double> p;
    for (int i=0;i<n;i++)
    {
        double a;
        cin>>a;
        p.push_back(a);
    }
    vector<vector<double>> dp;
    for (int i=0;i<n+1;i++)
    {
        vector<double> v1(n+1);
        dp.push_back(v1);
    }
    dp[0][0]=1;
    
    for (int i=1;i<n+1;i++)
    {
        for (int j=0;j<n+1;j++)
        {
            if (j==0)
            {
                dp[i][j]=(1-p[i-1])*dp[i-1][j];
            }
            else
            {
                dp[i][j]=(1-p[i-1])*dp[i-1][j]+p[i-1]*dp[i-1][j-1];
            }
            
        }
    }
    double sum=0;
    for(int i=n/2+1;i<=n;i++)
    {
        sum+=dp[n][i];
    }
    cout<<setprecision(9)<<sum;
    
}