#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll X;
  cin >> X;
  ll x[N];
  vector<ll> vec;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < N; i++) {
    vec.push_back(abs(x[i] - X));
  }
  for (int i = 1; i < N; i++) {
    vec.push_back(abs(x[i] - x[i-1]));
  }

  ll ans = vec[0];
  for (int i = 0; i < (int)vec.size(); i++) {
    ans = __gcd(ans,vec[i]);
  }
  cout << ans << endl;
  return 0;
}