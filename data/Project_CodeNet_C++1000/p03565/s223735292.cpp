#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1000000;
#define all(v) v.begin(), v.end()

int main(){
  string S,T;
  cin >> S >> T;
  ll s=S.size(),t=T.size(),y=0;
  rep(i,s-t+1){
    ll x=0;
    rep(j,t){
      if(!(T.at(t-1-j)==S.at(s-1-i-j)||S.at(s-1-i-j)=='?')){
        x=1;
        break;
      }
    }
    if(x==0){
      rep(j,t){
        S.at(s-1-i-j)=T.at(t-1-j);
      }
      rep(j,s-t+1-i){
        if(S.at(j)=='?'){
          S.at(j)='a';
        }
      }
      y=1;
      break;
    }else{
      if(S.at(s-1-i)=='?'){
        S.at(s-1-i)='a';
      }
    }
  }
  if(y==1){
    cout << S << endl;
  }else{
    cout << "UNRESTORABLE" << endl;
  }
}