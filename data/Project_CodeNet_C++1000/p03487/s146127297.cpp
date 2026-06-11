#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int>cnt;
int t,n,i,a;
cin>>n;
while(n--)
{
cin>>a;
cnt[a]++;
}
        int ans=0;
    for(auto u: cnt){
        if(u.second>=u.first) ans+=(u.second-u.first);
  else ans+=u.second;
    }
    cout<<ans<<endl;
}
