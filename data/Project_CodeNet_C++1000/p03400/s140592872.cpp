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
  ll N, D, X;
  cin >> N >> D >> X;
  vl A(N);
  rep(i, N) cin >> A[i];

  ll cnt = X;

  rep(i, N) cnt += (D - 1) / A[i] + 1;

  cout << cnt << endl;
  
  return 0;
}
