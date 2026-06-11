#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N;
  cin >> N;
  vector<ll> b(N),ans(N,0);
  rep(i,N) cin >> b.at(i);
  rep(j,N){
    ll t=1,x=-1;
    for(ll i=0;i<N;i++){
      if(b.at(i)==t){
        ans.at(N-1-j)=max(ans.at(N-1-j),t);
        x=max(x,i);
      }
      if(b.at(i)!=0){
        t++;
      }
    }
    if(x==-1){
      cout << -1 << endl;
      return 0;
    }
    b.at(x)=0;
  }
  rep(i,N){
    cout << ans.at(i) << endl;
  }
}