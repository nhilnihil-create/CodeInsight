#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  vl p(N);
  rep(i, N) cin >> p[i];

  stable_sort(p.begin(), p.end());

  ll ans = accumulate(p.begin(), p.end() - 1, 0LL);
  ans += p[N - 1] / 2;

  cout << ans << "\n";
  
  return 0;
}
