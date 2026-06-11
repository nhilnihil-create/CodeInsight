#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//const int MOD = 1000000007;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
//解答写し2次元累積和
int kazu[505][505];
int main(){
  int n,m,q;
  cin>>n>>m>>q;
  rep(i,m){
    int l,r;
    cin>>l>>r;
    kazu[l][r]++;
  }
  for(int i=1;i<505;i++){
    for(int j=1;j<505;j++){
      kazu[i][j]+=kazu[i][j-1];
    }
  }
  for(int j=1;j<505;j++){
    for(int i=1;i<505;i++){
      kazu[i][j]+=kazu[i-1][j];
    }
  }
  rep(i,q){
    int p,q;
    cin>>p>>q;
    int ans=kazu[q][q]-kazu[p-1][q]-kazu[q][p-1]+kazu[p-1][p-1];
    cout<<ans<<endl;
  }
  return 0;
}