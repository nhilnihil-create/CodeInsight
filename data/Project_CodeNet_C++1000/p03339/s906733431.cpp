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
  string S;
  cin >> S;

  vl west(N, 0), east(N, 0);

  rep2(i, 1, N) west[i] = west[i - 1] + (S[i - 1] == 'W' ? 1 : 0);
  rep_inv(i, N - 2, -1) east[i] = east[i + 1] + (S[i + 1] == 'E' ? 1 : 0);

  ll ans = N + 1;

  rep(i, N) ans = min(ans, west[i] + east[i]);

  cout << ans << endl;
  
  return 0;
}
