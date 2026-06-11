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
  ll T, A;
  cin >> T >> A;
  vl H(N);
  rep(i, N) cin >> H[i];

  ll dif = (ll)pow(10, 10);
  ll ans = -1;
  rep(i, N){
    if(dif > abs(1000*T - 6*H[i] - 1000*A)){
      ans = i + 1;
      dif = abs(1000*T - 6*H[i] - 1000*A);
    }
  }

  cout << ans << "\n";
  
  return 0;
}
