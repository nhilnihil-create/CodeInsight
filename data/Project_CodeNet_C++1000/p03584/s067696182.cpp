#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  vector<int> vec;
  // vec : vec[i] <= K && vec[i]の0のbitのいずれを1にしてもKを超えてしまうもの
  int N; ll K;
  cin >> N >> K;
  ll A[N],B[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  ll KK = K;
  ll s = 0;
  for (int i = 0; i < 30; i++) {
    if (KK < (1 << i+1) - 1) {
      s = i;
      break;
    }
  }
  vec.push_back((1 << s) - 1);
  ll now = 0;
  for (int bit = 29; bit >= 0; bit--) {
    if (KK > (1 << bit)) {
      KK -= (1 << bit);
      now += (1 << bit);
      int a = -1;
      for (int i = 0; i < 30; i++) {
        if (KK < (1 << i+1) - 1) {
          a = i;
          break;
        }
      }
      vec.push_back((1 << a) - 1 + now);
    }
  }
  ll ans = 0;
  for (int i = 0; i < (int)vec.size(); i++) {
    ll res = 0;
    for (int j = 0; j < N; j++) {
      bool in = true;
      for (int bit = 0; bit < 30; bit++) {
        if (vec[i] & (1 << bit)) {
          
        } else {
          if (A[j] & (1 << bit)) {
            in = false;
          }
        }
      }
      if (in) {
        res += B[j];
      }
    }
    ans = max(ans,res);
  }
  cout << ans << endl;
  return 0;
}