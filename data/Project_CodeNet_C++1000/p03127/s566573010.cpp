#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  int mini = 1001001001;
  int a[n];
  rep(i, n) {
    cin >> a[i];
    if (a[i] < mini) mini = a[i];
  }
  int next_mini = mini;
  while (next_mini > 0) {
    rep(i, n) {
      if (a[i] != mini) a[i] = a[i] % mini;
      if (a[i] < next_mini && a[i] != 0) next_mini = a[i];
    }
    if (next_mini == 1) {
      mini = 1;
      break;
    }
    if (mini == next_mini) {
      break;
    }
    mini = next_mini;
  }
  cout << mini << endl;
  return 0;
}