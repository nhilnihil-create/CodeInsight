#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
  ll n, m;
  cin >> n >> m;
  vector<P> ab(m);
  for (int i=0;i<m;++i) cin >> ab[i].second >> ab[i].first;

  sort(ab.begin(), ab.end());
  ll ra = 0;
  ll cnt = 0;
  for (int i=0;i<m;++i){
    if (ra <= ab[i].second){
      ++cnt;
      ra = ab[i].first;
    }
  }
  // rep(i, n) cout << arm[i].first << " " << arm[i].second << endl;
  cout << cnt << endl;
  return 0;
}
