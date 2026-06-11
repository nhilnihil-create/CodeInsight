#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    mp[a[i]]++;
  }

  int ans = 0;
  for (auto p: mp) {
    int x = p.first;
    int n = p.second;
    if (n < x) ans += n;
    else ans += n - x;
  }

  cout << ans << endl;
  return 0;
}
