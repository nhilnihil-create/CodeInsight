#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
const ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<ll> a(N),b(N);
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> b[i];
  }
  vector<ll> vec[28];
  vector<int> num(29);
  for (int i = 0; i < 29; i++) num[i] = 0; 
  for (int i = 0; i < 29; i++) {
    for (int j = 0; j < N; j++) {
      if ((1LL << i) & b[j]) {
        num[i]++;
      }
    }
  }
  for (int i = 0; i < N; i++) { 
    for (int j = 0; j < 28; j++) {
      vec[j].push_back(b[i] % (1LL << (j+1)));
    }
  }
  for (int i = 0; i < 28; i++) {
    sort(vec[i].begin(),vec[i].end());
  }
  for (int i = 0; i < N; i++) {
    if (a[i] % 2 == 0) {
      if (num[0] % 2 == 1) {
        ans ^= 1;
      }
    } else {
      if ((num[0] + N) % 2 == 1) {
        ans ^= 1;
      }
    }

    for (int bit = 0; bit < 28; bit++) {
      ll t = a[i] % (1LL << (bit+1));
      int s = vec[bit].end() - lower_bound(vec[bit].begin(),vec[bit].end(), (1LL << (bit+1)) - t);
      int l = 0;
      if (a[i] & (1LL << (bit+1))) {
        l = N;
      }
      if ((num[bit+1] + s + l) % 2 == 1) {
        ans ^= (1LL << (bit+1));
      }
    }
  }

  cout << ans << endl;
  return 0;
}