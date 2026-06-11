#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)

signed main(){

  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  using pii = pair<int,int>;
  vector<pii> queries(q);
  for(auto& q:queries)cin>>q.first>>q.second;

  vector<int> sum(n+1);
  rep(i,n-1){
    if(s[i]=='A'&&s[i+1]=='C')sum[i+1]++;
  }
  rep(i,n)sum[i+1]+=sum[i];
  //for(auto x:sum)cout<<x<<" ";cout<<endl;
  for(auto q:queries){
    cout<<sum[q.second-1]-sum[q.first-1]<<endl;
  }

}