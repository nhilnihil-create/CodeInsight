#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[3005][3005];

int main()
{
    string a,b;
    cin>>a>>b;
    a=' '+a;
    b=' '+b;
    ll sa=a.size();
    ll sb=b.size();
    int dp[sa+5][sb+5];
    for(ll i=0; i<sa; i++)
        for(ll j=0; j<sb; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

    int i=sa-1,j=sb-1;
    string ans="";
    while(i>0 && j>0){
        if(a[i]==b[j]){
            ans=a[i]+ans;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<ans<<endl;
}