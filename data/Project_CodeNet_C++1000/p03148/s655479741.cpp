#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define all(a) (a).begin(),(a).end()
#define loop(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) for(ll i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N, K; in(N); in(K);

  vvi neta(N);
  vi max_of(N, -1), rest;
  rep(i, N) {
    int t, d; in(t); in(d);
    --t;
    neta[t].push_back(d);
  }

  rep(i, N) {
    if (neta[i].size() == 0)
      continue;
    sort(neta[i].rbegin(), neta[i].rend());
    max_of[i] = neta[i][0];
    loop(j, 1, neta[i].size()) {
      rest.push_back(neta[i][j]);
    }
  }

  sort(max_of.rbegin(), max_of.rend());
  sort(rest.rbegin(), rest.rend());

  ll ans = 0, now = 0;
  rep(i, min((int)rest.size(), K))
    now += rest[i];

  rep(i, K) {
    if(max_of[i] == -1)
      break;
    now += max_of[i];
    if (K - (i+1) < rest.size())
      now -= rest[K - (i+1)];
    chmax(ans, (ll)now + (i+1)*(i+1));
  }
  out(ans);
  return 0;
}
