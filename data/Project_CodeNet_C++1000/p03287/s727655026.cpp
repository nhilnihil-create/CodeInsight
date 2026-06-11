#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long n,m;
  cin>>n>>m;
  vector<long>a(n);
  map<long,long>memo;
  long tot=0;
  rep(i,n){
    cin>>a.at(i);
    tot+=a.at(i);
    tot%=m;
    memo[tot]++;
  }
  long ans=0;
  for(auto p:memo){
    auto k=p.first;
    auto v=p.second;
    if(k==0){
      ans+=v*(v+1)/2;
    }
    else{
      ans+=v*(v-1)/2;
    }
  }
  cout<<ans<<endl;
}