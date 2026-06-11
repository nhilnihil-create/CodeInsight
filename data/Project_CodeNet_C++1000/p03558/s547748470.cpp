#include<iostream>
#include <bits/stdc++.h>
//1000000000000223
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int dp[100002], k;
queue<int> q;
int main()
{
    IO
    cin>>k;
    for(int i=0; i<=k; i++)
        dp[i]=k;
    for(int i=1; i<=9; i++)
        q.push(i), dp[i]=i;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<=9; i++)
        {
            int cur=(x*10+i)%k;
            if(dp[cur]>dp[x]+i)
                dp[cur]=dp[x]+i, q.push(cur);
        }
    }
    cout<<dp[0];
    return 0;
}
