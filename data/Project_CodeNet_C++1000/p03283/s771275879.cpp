#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll N,M,Q;
  cin >> N >> M >> Q;
  vector<vector<ll>> A(N,vector<ll>(N,0));
  rep(i,M){
    ll l,r;
    cin >> l >> r;
    A.at(l-1).at(r-1)++;
    
  }
  rep(i,N){
    rep(j,N){
      if(j!=0){
        A.at(i).at(j)+=A.at(i).at(j-1);
      }
    }
  }
  rep(i,N){
    rep(j,N){
      if(i!=0){
        A.at(N-1-i).at(j)+=A.at(N-i).at(j);
      }
    }
  }
  rep(i,Q){
    ll p,q;
    cin >> p >> q;
    p--;
    q--;
    cout << A.at(p).at(q) << endl;
  }
}