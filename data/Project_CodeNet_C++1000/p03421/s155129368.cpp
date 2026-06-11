#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  if (A > N || B > N) {
    cout << -1 << endl;
    return 0;
  }
  if ((B - 1) * A >= (N - A) && (B - 1) <= (N - A)) {
    int sum = N;
    for (int i = 0; i < A; i++) {
      cout << N - ((A - 1) - i) << " ";
    }
    sum -= A;
    for (int i = 0; i < B-1; i++) {
      int s = (N - A) / (B - 1);
      if (i < (N-A) % (B-1)) s++;
      for (int j = 0; j < s; j++) {
        cout << sum - (s - j) + 1 << " ";
      }
      sum -= s;
    }
    cout << endl;
  } else if ((A - 1) * B >= (N - B) && (A - 1) <= (N - B)) {
    int sum = 0;
    for (int i = 0; i < B; i++) {
      cout << B - i << " ";
    }
    sum += B;
    for (int i = 0; i < A-1; i++) {
      int s = (N - B) / (A - 1);
      if (i < (N-B) % (A-1)) s++;
      for (int j = 0; j < s; j++) {
        cout << sum + (s - j) << " ";
      }
      sum += s;
    }
    cout << endl;
  } else {
    cout << -1 << endl;
    return 0;
  }
  return 0;
}