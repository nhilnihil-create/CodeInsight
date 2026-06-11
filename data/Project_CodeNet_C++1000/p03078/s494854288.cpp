#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int x,y,z,k;
  cin>>x>>y>>z>>k;
  vector<long>a(x);
  vector<long>b(y);
  vector<long>c(z);
  
  rep(i,x){
    cin>>a.at(i);
  }
  rep(i,y){
    cin>>b.at(i);
  }
  rep(i,z){
    cin>>c.at(i);
  }
  vector<long>d;
  rep(i,x){
    rep(j,y){
      d.push_back(a.at(i)+b.at(j));
    }
  }
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  vector<long>e;
  rep(i,min(k,x*y)){
    rep(j,z){
      e.push_back(d.at(i)+c.at(j));
    }
  }
  sort(e.begin(),e.end());
  reverse(e.begin(),e.end());
  
  rep(i,k){
    cout<<e.at(i)<<endl;
  }
}
            