#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  ll H;
  cin >> N >> H;
  ll a[N],b[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  ll top_a = 0;
  vector<ll> throw_(0);
  for (int i = 0; i < N; i++) {
    top_a = max(top_a , a[i]);
  }
  for (int i = 0; i < N; i++) {
    if (b[i] > top_a) {
      throw_.push_back(b[i]);
    }
  }
  sort(throw_.begin(),throw_.end());
  reverse(throw_.begin(),throw_.end());
  ll sum = 0;
  ll cnt = 0;
  for (int i = 0; i < (int)throw_.size(); i++) {
    sum += throw_[i];
    cnt++;
    if (sum >= H) {
      break;
    }
  }
  if (sum >= H) {
    cout << cnt << endl;
  } else {
    cnt += (H - sum + (top_a - 1)) / top_a;
    cout << cnt << endl;
  }
  return 0;
}