#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n;
  cin >> n;
 
 
  vector<vector<int>> x(n,vector<int>(10));
  rep(i,n) {
    rep(j,10){
      cin >> x.at(i).at(j);
    }
  }
  vector<vector<int>> p(n,vector<int>(11));
  rep(i,n) {
    rep(j,11){
      cin >> p.at(i).at(j);
    }
  }
  int ans=-1001001001;
  for (int tmp = 1; tmp < (1 << 10); tmp++) {
    bitset<10> s(tmp);
    vector<int>co(n);
    rep(i,10){
      if(s.test(i)){
        rep(j,n){
          if(x.at(j).at(i)==1){
            co.at(j)++;
          }
        }
      }
    }
    int now=0;
    rep(i,n){
      now+=p.at(i).at(co.at(i));
    }
    ans=max(ans,now);       
  }  
  cout<<ans<<endl;
}