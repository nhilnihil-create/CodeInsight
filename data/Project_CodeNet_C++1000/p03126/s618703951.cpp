#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n,m;cin>>n>>m;
  vector<int> vec(m,0);
  rep(j,n){
    int k;cin>>k;
    vector<int> v(k);
    rep(i,k){
      cin>>v.at(i);
      vec.at(v.at(i)-1)++;
    }
  }
  cout<<count(vec.begin(),vec.end(),n);
}
      


