
#include <bits/stdc++.h>
using namespace std;

int  main() {
    long long n,m;
   cin>>n>>m;
  vector<pair<int, int>> mp(n);
    long long a,b;
for(int i=0;i<n;i++)
  
{
    cin>>a>>b;
    mp[i]=make_pair(a,b);
}
   sort(mp.begin(), mp.end());
 long long count=0,ans=0;
for(int i=0;i<n;i++)
{
    int tmp;
    if(mp[i].second<= m)
             tmp= mp[i].second ;
            else
              tmp= m ;
        ans += (long long)mp[i].first * tmp;
        m -= tmp;
        if (m == 0) break;
    

}
       cout<<ans;
}
