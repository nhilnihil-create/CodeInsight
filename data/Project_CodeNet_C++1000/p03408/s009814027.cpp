#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  map<string,int> m;
  int n,a,ma;
  string w;
  cin>>n;
  rep(i,n){
    cin>>w;
    if(m.count(w)){
      m[w]++;
    }else{
      m[w]=1;
    }
  }
  cin >>a;
  rep(i,a){
    cin>>w;
    if(m.count(w)){
      m[w]--;
    }else{
      m[w]=-1;
    }
    
  }
  for(auto p:m){
    ma=max(ma,p.second);
  }
  cout <<ma<<endl;
}