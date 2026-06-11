#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main()
{
  int n;int m;cin>>n>>m;
  priority_queue<pair<int,int>>pq;
  for(int i=1;i<=n;i++)
  {
    int a;cin>>a;pq.push({a,1});
  }
  for(int i=1;i<=m;i++)
  {
    int b;int c;cin>>b>>c;
    pq.push({c,b});
  }
  
  int ans=0;
  for(int i=0;i<n;i++)
  {
    pair<int,int> temp=pq.top();
    pq.pop();
    ans+=temp.first;
    if(temp.second>1)
      pq.push({temp.first,temp.second-1});
  }
  cout<<ans<<endl;
}