#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int i,j,n,x,y,z;
    cin >> n;
    vector<vector<long long int> >A(n);
    for(i=0;i<n;++i){
        cin >> x >>y >>z;
        A[i].push_back(x);
        A[i].push_back(y);
        A[i].push_back(z);
    }
    vector<vector<long long int> >dp(n,vector<long long int>(3,0));
    dp[0][0]=A[0][0];
    dp[0][1]=A[0][1];
    dp[0][2]=A[0][2];
    for(i=1;i<n;++i){
        dp[i][0]=A[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=A[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=A[i][2]+max(dp[i-1][1],dp[i-1][0]);
    }
    x=0;
    for(i=0;i<3;++i)
    x=max(x,dp[n-1][i]);
    cout << x <<endl;

    return 0;
}