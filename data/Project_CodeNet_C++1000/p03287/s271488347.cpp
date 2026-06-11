#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N_MAX = 1e5 + 10;

ll N, M;
ll A[N_MAX], B[N_MAX];

void solve(){
  
  unordered_map<ll, ll> x;
  for(ll i = 0; i <= N; i++){
    x[B[i]]++;
  }

  ll ans = 0;

  for(auto p : x){
    ans += (p.second * (p.second - 1)) / 2;
  }

  cout << ans << endl;
}


int main() {

  cin >> N >> M;
  B[0] = 0;
  for(ll i = 0; i < N; i++){
    cin >> A[i];
    B[i+1] = B[i] + A[i];
    B[i+1] %= M;
  }

  solve();
}