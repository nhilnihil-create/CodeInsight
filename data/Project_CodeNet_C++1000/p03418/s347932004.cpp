#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using vb = vector<bool>;
using boolGraph = vector<vb>;
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int N, K; cin >> N >> K;

  ll ans = 0;
  for (int b=K+1; b<=N; ++b) {
    ans += (b-K) * (N/b) + max(0, N%b - (K-1));
  }

  if (K == 0) ans -= N;
  
  cout << ans << endl;
  return 0;
}
