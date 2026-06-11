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
  ll N, M;
  cin >> N >> M;
  vl A(N);
  rep(i, N) cin >> A[i];

  ll ans = 0;

  map<ll, ll> rem_cnt;
  rem_cnt[0]++;
  
  ll sum = 0;
  rep(i, N){
    sum += A[i] % M;
    sum %= M;
    
    rem_cnt[sum]++;
  }
  
  ll cnt;

  for(auto it = rem_cnt.begin(); it != rem_cnt.end(); it++){
    cnt = it->second;
    ans += cnt * (cnt - 1) / 2;
  }

  cout << ans << endl;
  
  return 0;
}
