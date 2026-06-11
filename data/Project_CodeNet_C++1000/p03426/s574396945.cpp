#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll H,W,D,Q;
  cin >> H >> W >> D;
  vector<vector<ll>> B(D,vector<ll>(H*W/D+1,0));
  vector<P> A(H*W);
  rep(i,H)rep(j,W){
    ll k;
    cin >> k;
    A.at(k-1)=P(i,j);
  }
  rep(i,H*W){
    if(i<D){
      B.at(i).at(i/D)=0;
    }else{
      B.at(i%D).at(i/D)=B.at(i%D).at(i/D-1)+abs(A.at(i-D).first-A.at(i).first)+abs(A.at(i-D).second-A.at(i).second);
    }
  }
  cin >> Q;
  rep(i,Q){
    ll l,r;
    cin >> l >> r;
    cout << B.at((r-1)%D).at((r-1)/D)-B.at((l-1)%D).at((l-1)/D) << endl;
  }
}
      