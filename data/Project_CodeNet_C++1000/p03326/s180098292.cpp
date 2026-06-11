#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n, m;
  cin >> n >> m;
  vector<ll> x(n), y(n), z(n);
  rep(i, n) {
    cin >> x[i] >> y[i] >> z[i];
  }
  ll ans = LLONG_MIN;
  rep(i, 2)rep(j, 2)rep(k, 2) {
    vector<ll> score(n);
    ll t = 0;
    rep(l, n) {
      score[l] += i ? x[l] : -x[l];
      score[l] += j ? y[l] : -y[l];
      score[l] += k ? z[l] : -z[l];
    }
    sort(score.rbegin(), score.rend());
    rep(l, m) t += score[l];
    ans = max(ans, t); 
  }
  cout << ans << endl;
  
}