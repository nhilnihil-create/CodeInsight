#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,ans=0;
  cin >> N;
  vector<ll> D(13,0);
  rep(i,N){
    ll d;
    cin >> d;
    D.at(d)++;
  }
  rep(i,13){
    if(i==0){
      if(D.at(i)>0){
        cout << 0 << endl;
        return 0;
      }
    }else if(i==12){
      if(D.at(i)>1){
        cout << 0 << endl;
        return 0;
      }
    }else{
      if(D.at(i)>2){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  for (int tmp = 0; tmp < (1 << 11); tmp++) {
    bitset<11> s(tmp);
    vector<ll> A(24,0);
    A.at(0)=1;
    rep(i,12){
      if(i<11){
        if(D.at(i+1)==2){
          A.at(i+1)=1;
          A.at(23-i)=1;
        }else if(D.at(i+1)==1){
          if(s.test(i)){
            A.at(i+1)=1;
          }else{
            A.at(23-i)=1;
          }
        }
      }else{
        if(D.at(i+1)==1){
          A.at(i+1)=1;
        }
      }
    }
    ll x=INF,t=1;
    rep(i,24){
      if(A.at((i+1)%24)==1){
        x=min(x,t);
        t=1;
      }else{
        t++;
      }
    }
    ans=max(x,ans);
  }
  cout << ans << endl;
}