#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);

 //string ans="";
/*ll solve(ll n )
 {
     if(n<12)
        return n;
     if(mp[n]==0)
            mp[n]=max(solve(n/2)+solve(n/3)+solve(n/4),n);
     return mp[n];
        
 }
*/

int main()
{
   
    fast;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
      string s;cin>>s;
      if(s.length()!=a+b+1)
        cout<<"No\n";
      else if(s[a]!='-')
        cout<<"No\n";
     else {
         ll i,f=0;
         for( i=0;i<a;i++)
         {if(s[i]>='0'&&s[i]<='9')
             continue;
             else
                {f=1;break;}
         }
         for(i=a+1;i<a+b+1;i++)
         {if(s[i]>='0'&&s[i]<='9')
             continue;
             else
                {f=1;break;}
         }
         if(f)
            cout<<"No\n";
         else
            cout<<"Yes\n";
     }    
      
    }
}