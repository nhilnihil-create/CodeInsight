#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> x(N);
  for (int i=0; i<N; i++) cin >> x[i];
  vector<ll> res;
  for (int l=0; l<N-K+1; l++) {
    int r = l+K-1;
    ll num1 = abs(x[l])+abs(x[r]-x[l]), num2 = abs(x[r])+abs(x[r]-x[l]);
    res.push_back(min(num1, num2));
  }
  sort(res.begin(), res.end());
  cout << res[0] << endl;
  return 0;
}