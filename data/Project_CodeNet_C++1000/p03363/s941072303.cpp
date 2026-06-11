#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main() {
  int n;
  cin>>n;
  vector<long>a(n);
  vector<long>t(n);
  long to=0;
  rep(i,n){
    cin>>a.at(i);
    to+=a.at(i);
    t.at(i)=to;
  }
  map<long,long>memo;
  memo[0]=1;
  rep(i,n){
    memo[t.at(i)]++;
  }
  long ans=0;
  for(auto p:memo){
    auto k=p.second;
    ans+=k*(k-1)/2;
  }
  cout<<ans<<endl;
}