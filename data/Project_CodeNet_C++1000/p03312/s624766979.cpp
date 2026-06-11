#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++) {
  	cin >> A[i];
  }
  vector<ll> acc(N + 1);
  for(int i = 0; i < N; i++) {
    acc[i + 1] = acc[i] + A[i];
  }
  
  ll ans = 1LL << 62;
  for(int j = 2; j <= N - 2; j++) {
    int i1 = lower_bound(all(acc), acc[j] / 2) - acc.begin();
    int k1 = lower_bound(all(acc), (acc[N] + acc[j]) / 2) - acc.begin();
    vector<int> I = {i1}, K = {k1};
	if (i1 - 1 >= 0) I.push_back(i1 - 1);
    if (k1 - 1 > j) K.push_back(k1 - 1);
    for(int u = 0; u < I.size(); u++) {
      for(int v = 0; v < K.size(); v++) {
        int i = I[u], k = K[v];
        vector<ll> sum = {acc[N] - acc[k], acc[k] - acc[j], acc[j] - acc[i], acc[i]};
        sort(all(sum));
        ans = min(ans, sum.back() - sum[0]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}