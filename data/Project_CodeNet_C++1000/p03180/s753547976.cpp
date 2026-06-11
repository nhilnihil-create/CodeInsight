/*
    author: kartik8800
*/
#include<bits/stdc++.h>
#define ll long long
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define triplet pair<int,pair<int,int>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll dp[(1<<16)];
ll sums[(1<<16)];

ll calculate(vector<vector<int>>& score,int mask)
{
    ll ans = 0;
    for(int i = 0; i < 17; i ++)
    {
        for(int j = i+1; j < 17; j ++)
        {
            if(((mask&(1<<i))!=0) && ((mask&(1<<j))!=0))
                ans += score[i][j];
        }
    }
    return ans;
}

void prepareSums(vector<vector<int>>& score,int n)
{
    for(int subset = 1; subset < (1<<n); subset++)
        dp[subset] = inf;
    for(int subset = 1; subset < (1<<n); subset++)
        sums[subset] = calculate(score, subset);
}

ll solve(vector<vector<int>>& score,int mask)
{
    if(mask == 0)
        return 0;
    if(dp[mask] != inf)
        return dp[mask];
    
    ll ans = 0;
    for(int submask = mask; submask != 0; submask = (submask-1)&mask)
         ans = max(ans, sums[submask] + solve(score, mask ^ submask));
    
    return dp[mask] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> score(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> score[i][j];
    prepareSums(score,n);
    cout << solve(score, (1<<n) - 1);
    return 0;
}
