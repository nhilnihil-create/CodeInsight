#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,k,i=0,j,c=0,p,m=0,max=0,h[100000],dp[100000],saisyo=100000000;
    string s;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
    }
    for(i=1;i<=k;i++)
    {
        dp[i]=abs(h[0]-h[i]);
    }
    for(i=k;i<n;i++)
    {   
        for(j=1;j<=k;j++)
        {
            if(saisyo>abs(h[i]-h[i-j])+dp[i-j])
            {
                saisyo=abs(h[i]-h[i-j])+dp[i-j];
            }
        }
        dp[i]=saisyo;
        saisyo=1000000000;
    }
    cout << dp[n-1] << endl;
    return 0;

}
