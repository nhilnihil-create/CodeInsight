#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)n;++i)
using P = pair<ll,ll>;

int main(){
  int n;cin >> n;
  map<int,int> d;
  rep(i,n){
    int num;cin >> num;
    d[num]++;
  }

  int m;cin >> m;
  vector<int> t(m);
  rep(i,m) cin >> t.at(i);

  rep(i,m){
    if( d[t.at(i)] == 0 ){
      cout << "NO" << '\n';
      return 0;
    }else{
      d.at(t.at(i))--;
    }
  }
  cout << "YES" << '\n';
  return 0;
}