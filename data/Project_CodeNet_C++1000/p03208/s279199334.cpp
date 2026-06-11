#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, K; cin >> N >> K;
  vector<ll> h(N);
  rep(i,N) cin >> h[i];
  sort(h.begin(), h.end(), greater<ll>());
  ll min_dif = 1000000010;
  rep(i,N-K+1) {
    ll temp_dif = h[i] - h[i+K-1];
    min_dif = min(min_dif, temp_dif);
  }
  cout << min_dif << endl;
  return 0;
}