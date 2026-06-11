#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,n) {
    cin >> v.at(i);
  }
  map<int,int>memo1,memo2;
  rep(i,n){
    if(i%2==0){
      memo1[v.at(i)]++;
    }
    else{
      memo2[v.at(i)]++;
    }
  }
  int g1=0;
  int g2=0;
  int k1=0;
  int k2=0;
  int ga,gb,ka,kb;
  for (auto p:memo1) {
    auto ke = p.first;
    auto va = p.second;
    if(g1<va&&g2<va){
      g2=g1;
      g1=va;
      gb=ka;
      ga=ke;
    }
    else if(g1>=va&&g2<va){
      g2=va;
      gb=ke;
    }
  }
  for (auto p:memo2) {
    auto ke = p.first;
    auto va = p.second;
    if(k1<va&&k2<va){
      k2=k1;
      k1=va;
      kb=ka;
      ka=ke;
    }
    else if(g1>=va&&g2<va){
      g2=va;
      gb=ke;
    }
  }
  if(ga!=ka){
    cout<<n-g1-k1<<endl;
  }
  else{
    if(g1+k2<g2+k1){
      cout<<n-g2-k1<<endl;
    }
    else{
      cout<<n-g1-k2<<endl;
    }
  }
}