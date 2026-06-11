#include <bits/stdc++.h>
#define lol long long
using namespace std;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  lol n,p;
  cin >>n>>p;
  map<lol,lol> sum;
  lol ans=1;
  lol limit=p;
  for(lol i=2;i*i+5<=limit;i++){
    while(p%i==0){
      sum[i]++;
      p/=i;
    }
  }
  if(p!=1) sum[p]++;
  for(auto e:sum){
    ans*=pow(e.first,e.second/n);
  }
  cout <<ans<<'\n';
  return (0);
}