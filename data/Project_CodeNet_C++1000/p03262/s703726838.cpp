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

ll gcd(ll m, ll n){
  ll m1 = m, n1 = n;
  ll tmp;

  while(n1 != 0){
    tmp = n1;
    n1 = m1 % n1;
    m1 = tmp;
  }

  return m1;
}

int main(){
  ll N, X;
  cin >> N >> X;
  vl x(N);
  rep(i, N) cin >> x[i];

  ll tmp;
  ll ans = abs(x[0] - X);

  rep2(i, 1, N){
    tmp = abs(x[i] - X);
    ans = gcd(ans, tmp);
  }

  cout << ans << "\n";
  
  return 0;
}
