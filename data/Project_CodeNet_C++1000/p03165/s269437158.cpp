#include <bits/stdc++.h>
using namespace std;
#define ll long long
string fun(string s, string t, ll m, ll n)
{
    ll dp[m+1][n+1];
    ll i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    i=m;
    j=n;
    string st="";
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            st+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
            j--;
        else
            i--;
    }
    reverse(st.begin(),st.end());
    return st;
}
 
int main() {
   
   string s,t;
   cin>>s>>t;
   ll m=s.length();
   ll n=t.length();
   cout<<fun(s,t,m,n);
    
}