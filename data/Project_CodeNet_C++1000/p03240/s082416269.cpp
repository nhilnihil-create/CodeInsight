#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  vector<int> X(n),Y(n),H(n);
  rep(i,n) cin>>X[i]>>Y[i]>>H[i];

  set<int> s;
  set<pair<int,int>> t;
  rep(i,101){
    rep(j,101){
      rep(k,n){
        if(H[k]==0){
          t.insert({X[k],Y[k]});
          continue;
        }
        s.insert(abs(X[k]-i)+abs(Y[k]-j)+H[k]);
      }
      if(s.size()==1){
        bool b=true;
        for(auto x:t){
          if((*begin(s)-abs(x.first-i)-abs(x.second-j))>0) b=false;
        }
        if(b){
          cout<<i<<" "<<j<<" "<<*begin(s)<<endl;
          return 0;
        }
      }
      s.clear();
      t.clear();
    }
  }

  return 0;
}