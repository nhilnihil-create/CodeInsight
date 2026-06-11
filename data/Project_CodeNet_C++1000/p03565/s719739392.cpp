#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}



int main(){
  string S,T;
  cin >> S >> T;
  ll s=S.size(),t=T.size(),x=0;
  rep(i,s-t+1){
    rep(j,t){
      if(S.at(s-1-i-j)!=T.at(t-1-j)&&S.at(s-1-i-j)!='?'){
        break;
      }
      if(j==t-1){
        rep(k,t){
          S.at(s-1-i-k)=T.at(t-1-k);
        }
        rep(k,s){
          if(S.at(k)=='?'){
            S.at(k)='a';
          }
          x=1;
        }
      }
    }
    if(x==1){
      break;
    }
  }
  if(x==1){
    cout << S << endl;
  }else{
    cout << "UNRESTORABLE" << endl;
  }
}
          
          