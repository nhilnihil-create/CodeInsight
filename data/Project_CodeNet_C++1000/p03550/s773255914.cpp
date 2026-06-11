#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,Z,W;
  cin >> N >> Z >> W;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);
  if(N==1) cout << abs(A.at(N-1)-W) << endl;
  else cout << max(abs(A.at(N-1)-W),abs(A.at(N-1)-A.at(N-2))) << endl;
}