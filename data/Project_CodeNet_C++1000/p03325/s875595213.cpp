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
  vl a(N);
  rep(i, N) cin >> a[i];

  ll ans = 0;
  ll p;

  rep(i, N){
    p = 0;
    while(a[i] % 2 == 0){
      a[i] /= 2;
      p++;
    }
    ans += p;
  }

  cout << ans << endl;
  
  return 0;
}
