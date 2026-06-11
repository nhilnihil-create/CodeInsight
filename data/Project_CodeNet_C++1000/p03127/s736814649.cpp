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
  ll m1 = m, n1 = n, tmp;

  while(n1 != 0){
    tmp = n1;
    n1 = m1 % n1;
    m1 = tmp;
  }

  return m1;
}

int main(){
  ll N;
  cin >> N;
  vl A(N);
  rep(i, N) cin >> A[i];

  ll ans = gcd(A[0], A[1]);

  rep2(i, 2, N) ans = gcd(ans, A[i]);

  cout << ans << "\n";
  
  return 0;
}
