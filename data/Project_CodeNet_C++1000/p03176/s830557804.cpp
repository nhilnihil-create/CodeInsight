#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define int ll
struct flower
{
   int h;
   int b;
};
signed main(void)
{
   int n;
   cin>>n;
   vector< flower >v(n+1);
   vector< int >dp(n+1);
   for(int  i = 1;i<=n;i++)
    cin>>v[i].h;
  for(int  i =1;i<=n;i++)
    cin>>v[i].b;
   map<int,int>mp;
   dp[1] = v[1].b;
   mp[v[1].h] = dp[1];
   int ans = dp[1];
   for(int  i = 2;i<=n;i++)
   {

       dp[i] = v[i].b;
       auto it = mp.lower_bound((v[i].h+1));
       if(it!= mp.begin())
       {
          it--;
          dp[i]+= (it->second);
       }

       mp[v[i].h] = dp[i];

       it = mp.upper_bound(v[i].h);

       while(it!=mp.end() && (it->second)<= dp[i])
       {
           auto temp = it;
           temp++;
           mp.erase(it);
           it = temp;
       }

       if(ans<dp[i])
        ans = dp[i];
   }
   cout<<ans<<endl;

}