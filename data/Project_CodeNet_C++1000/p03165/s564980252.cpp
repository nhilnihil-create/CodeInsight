#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define vl vector<long long int>
#define vvl vector<vector<ll> > 
#define fo(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b)  for(int i=b;i>=a;i--)
using namespace std;
ll mod=1000000007;

int main()
{
    string s,t;cin>>s>>t;
    ll n=s.length(),m=t.length();
    ll dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    fo(i,1,n+1)
        fo(j,1,m+1)
        {
            if(s[i-1]==t[j-1])
                dp[i][j] = max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    ll i=n-1,j=m-1;
    string res;
    while(i>=0&&j>=0)
    {
        if(s[i]==t[j])
        {
            res+=s[i];
            i--;j--;
        }
        else if(dp[i][j+1]>=dp[i+1][j])
            i--;
        else
            j--;
    }
    reverse(res.begin(),res.end());
    cout << res;
}

