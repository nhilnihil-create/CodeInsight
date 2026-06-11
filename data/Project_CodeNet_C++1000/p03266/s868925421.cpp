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
  ll N, K;
  cin >> N >> K;

  if(N < K / 2){
    cout << 0 << "\n";
    return 0;
  }
  
  ll n1 = N / K;
  ll ans = n1 * n1 * n1;

  if(K % 2 == 0){
    n1 = (N - K / 2) / K + 1;
    ll tmp = n1 * n1 * n1;
    ans += tmp;
  }

  cout << ans << "\n";
  
  return 0;
}
