#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int t[N],x[N],y[N];
  for (int i = 0; i <N; i++) cin >> t[i] >> x[i] >> y[i];
  bool can = true;
  int time = 0;
  int nx = 0;
  int ny = 0;
  for (int i = 0; i < N; i++) {
    int diff = abs(x[i] - nx) + abs(y[i] - ny);
    if (diff <= t[i] - time && diff % 2 == (t[i] - time) % 2) {
      time = t[i];
      nx = x[i];
      ny = y[i];
    } else {
      can = false;
      break;
    }
  }
  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}