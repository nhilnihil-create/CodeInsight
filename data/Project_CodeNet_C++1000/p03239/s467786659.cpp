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
  ll N, T;
  cin >> N >> T;
  vl c(N), t(N);
  rep(i, N) cin >> c[i] >> t[i];

  ll cost = 10000;

  rep(i, N){
    if(t[i] <= T) cost = min(cost, c[i]);
  }

  if(cost == 10000)
    cout << "TLE\n";
  else
    cout << cost << "\n";
  
  return 0;
}
