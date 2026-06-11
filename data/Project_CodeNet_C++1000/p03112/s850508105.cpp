#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const ll INF = pow(10, 18);

int main(){
  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a);
  vector<ll> t(b);
  rep(i, a) cin >> s[i];
  rep(i, b) cin >> t[i];
  s.push_back(INF); s.push_back(-INF);
  t.push_back(INF); t.push_back(-INF);
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  vector<ll> res;
  rep(i, q) {
    ll x;
    cin >> x;
    ll ans = INF;
    rep(j, 2) {
      int first;
      if(j % 2) {
        first = lower_bound(s.begin(), s.end(), x) - s.begin();
      } else {
        first = upper_bound(s.begin(), s.end(), x) - s.begin() - 1;
      }
      rep(k, 2) {
        int second;
        if(k % 2) {
          second = lower_bound(t.begin(), t.end(), s[first]) - t.begin();
        } else {
          second = upper_bound(t.begin(), t.end(), s[first]) - t.begin() - 1;
        }
        ans = min(ans, abs(x - s[first]) + abs(s[first] - t[second]));
      }
    }
    
    rep(j, 2) {
      int first;
      ll tmp = 0;
      if(j % 2) {
        first = lower_bound(t.begin(), t.end(), x) - t.begin();
      } else {
        first = upper_bound(t.begin(), t.end(), x) - t.begin() - 1;
      }
      rep(k, 2) {
        int second;
        if(k % 2) {
          second = lower_bound(s.begin(), s.end(), t[first]) - s.begin();
        } else {
          second = upper_bound(s.begin(), s.end(), t[first]) - s.begin() - 1;
        }
        ans = min(ans, abs(x - t[first]) + abs(t[first] - s[second]));
      }
    }
    res.push_back(ans);
  }
  rep(i, q) cout << res[i] << endl;
}