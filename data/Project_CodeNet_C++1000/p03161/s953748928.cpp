#include <iostream>
#include <bits/stdc++.h>
#include<string>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2;i<n;i++)
    {
        int j=1;
        while(i-j>=0&&j<=k)
        {
            dp[i] = min(dp[i-j]+abs(h[i ]-h[i-j]),dp[i]);
            j++;
        }
    }
    cout<<dp[n-1];
	return 0;
}