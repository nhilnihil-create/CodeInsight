#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()



int main(){
  ll N,M,t=0,ans=0;
  cin >> N >> M;
  vector<P> A(M);
  rep(i,M) cin >> A.at(i).first >> A.at(i).second;
  sort(all(A));
  rep(i,M){
    ll m=A.at(i).second;
    while(t<M&&A.at(t).first<m){
      m=min(m,A.at(t).second);
      t++;
    }
    ans++;
    i=t-1;
  }
  cout << ans << endl;
}
  