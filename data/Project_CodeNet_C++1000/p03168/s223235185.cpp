#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

double solve( vector<vector<double> > &dp ,int coins,int head,vector<double> &prob)
{
    if(head < 0)
        return 0.0;
    if(coins < 0)
        return head==0;
    if(dp[coins][head]!=-1)
        return dp[coins][head];
    return dp[coins][head] =(prob[coins]*solve(dp,coins-1,head-1,prob) + (1-prob[coins])*solve(dp,coins-1,head,prob));

}

int32_t main()
{
    int coins;
    cin>>coins;
    vector<double> prob(coins);
    for(int i=0;i<coins;i++)
        cin>>prob[i];
    vector<vector<double> > dp(coins+1,vector<double> (coins+1,-1));

    double ans=0;
    for(int head=(coins+1)/2;head<=coins;head++)
    {
        ans+=solve(dp,coins-1,head,prob);
    }
            cout<<setprecision(10);
        cout<<ans<<endl;
}