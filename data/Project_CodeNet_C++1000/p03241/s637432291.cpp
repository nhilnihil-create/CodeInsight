#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pr(ll x){//因数の個数を返す
  vector<ll> v;
  ll y = x;
  for(ll i = 2LL;i*i<=x;i++) {
    if(y%i==0LL){
      ll z = 0LL;
      while(y%i==0LL){
        y/=i;
        z++;
      }
      v.push_back(z);
    }
  }
  if(y!=1LL) v.push_back(1LL);
  ll cnt = 1LL;
  for(auto t:v){
    cnt*=(t+1);
  }
  return cnt;
}

int main() {
  ll N,M;
  cin>>N>>M;
  ll t = M;
  if(pr(M)!=2LL){
    for(ll i = N; i <= M;i++) {
      if(M%i==0LL){
        t=i;
        break;
      }
    }
  }
  cout<<M/t<<endl;
}