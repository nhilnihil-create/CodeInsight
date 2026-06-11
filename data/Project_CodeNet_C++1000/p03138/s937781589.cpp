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


int main(){
  ll N,K;
  cin >> N >> K;
  vector<string> A(N);
  rep(i,N){
    ll a;
    cin >> a;
    string S;
    rep(j,40){
      if(a>=(ll)pow(2,39-j)){
        a-=(ll)pow(2,39-j);
        S+='1';
      }else{
        S+='0';
      }
    }
    A.at(i)=S;
  }
  ll x=0,X=0,Y=0;
  rep(i,40){
    if(x==0){
      if(K>=(ll)pow(2,39-i)){
        x=(ll)pow(2,39-i);
        rep(j,N){
          if(A.at(j).at(i)=='0'){
            X+=(ll)pow(2,39-i);
          }
        }
        rep(j,N){
          if(A.at(j).at(i)=='1'){
            Y+=(ll)pow(2,39-i);
          }
        }
      }else{
        rep(j,N){
          if(A.at(j).at(i)=='1'){
            Y+=(ll)pow(2,39-i);
          }
        }
        X=Y;
      }
    }else{
      if(K>=x+(ll)pow(2,39-i)){
        ll a=0;
        rep(j,N){
          if(A.at(j).at(i)=='1'){
            a++;
          }
        }
        Y=max(Y+a*(ll)pow(2,39-i),max(Y+(N-a)*(ll)pow(2,39-i),X+a*(ll)pow(2,39-i)));
        x+=(ll)pow(2,39-i);
        X+=(N-a)*(ll)pow(2,39-i);
      }else{
        ll a=0;
        rep(j,N){
          if(A.at(j).at(i)=='1'){
            a++;
          }
        }
        Y=max(Y+a*(ll)pow(2,39-i),Y+(N-a)*(ll)pow(2,39-i));
        X+=a*(ll)pow(2,39-i);
      }
    }
  }
  cout << max(X,Y) << endl;
        
}