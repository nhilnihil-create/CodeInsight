#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#define ios   ios_base::sync_with_stdio(false);  cin.tie(0);    cout.tie(0);
typedef   long long int ll;
using namespace std;
const int N=3e3+5;
#define fi first
#define se second
#define pb push_back
#define endl "\n"
ll ans[N][N];
int main()
{
    string s,t;cin>>s>>t;
    ll n=s.length(),m=t.length();
    for(ll i=1;i<=n;++i)
    {
        for(ll j=1;j<=m;++j)
        {
           if(s[i-1]==t[j-1])
           {
               ans[i][j]=ans[i-1][j-1]+1;
           }
           else
           ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
        }
    }
    string  res="";
    ll i=n,j=m;
    while(i && j)
    {
        if(ans[i][j]!=ans[i][j-1] && ans[i][j]!=ans[i-1][j])
        {
            res+=t[j-1];
            --i;
            --j;
        }
        else
       if(ans[i][j]==ans[i][j-1])
       {
        //res+=t[j-1];
       --j;
       }
       else
       if(ans[i][j]==ans[i-1][j])
       {
         --i;
       }

    }
    ll u=res.size();
    for(ll i=u-1;i>=0;--i)
    cout<<res[i];
   /* for(ll i=0;i<=n;++i)
    {
        for(ll j=0;j<=m;++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }*/

}