#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  int N;
  ll x;
  cin >> N >> x;
  vector<ll> a(N);
  ll sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll count = 0;
  int ans = 0;
  bool b = true;
  int k;
  for(int i = 0; i < N; i++) {
    if(x - count >= a[i]) {
      count += a[i];
      ans++;
    }
    else {
      b = false;
      break;
    }
  }
  if(b && count != x) {
    ans--;
  }
  cout << ans << endl;
}