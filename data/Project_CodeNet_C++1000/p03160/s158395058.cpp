#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,i=0,j,c=0,p,m=0,max=0,h[100000],dp[100000];
    string s;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
    }
    dp[1]=abs(h[0]-h[1]);
    dp[2]=abs(h[0]-h[2]);
    for(i=3;i<n;i++)
    {   
        dp[i]=min(abs(h[i]-h[i-2])+dp[i-2],abs(h[i]-h[i-1])+dp[i-1]);
    }
    cout << dp[n-1] << endl;
    return 0;

}
