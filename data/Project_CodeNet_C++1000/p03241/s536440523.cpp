#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;

vector<P> prime;
vector<ll> cand;
void DFS(int t,ll res) {
  if (t == prime.size()) {
    cand.push_back(res);
  } else {
    ll a = 1;
    for (int i = 0; i <= prime[t].second; i++) {
      DFS(t+1,res*a);
      a *= prime[t].first;
    }
  }
  return ;
}

int main() {
  ll N,M;
  cin >> N >> M;
  ll Mm = M;
  // Mを素因数分解
  int cnt = 0;
  for (ll i = 2; i * i <= M; i++) {
    if (M % i == 0) {
      prime.push_back(make_pair(i,0));
      while (M % i == 0) {
        M /= i;
        prime[cnt].second++;
      }
      cnt++;
    }
  }
  if (M != 1) {
    prime.push_back(make_pair(M,1));
  }
  DFS(0,1);
  ll ans = -1;
  for (int i = 0; i < cand.size(); i++) {
    if (Mm / cand[i] >= N) {
      ans = max(ans,cand[i]);
    }
  }
  cout << ans << endl;
  return 0;
}