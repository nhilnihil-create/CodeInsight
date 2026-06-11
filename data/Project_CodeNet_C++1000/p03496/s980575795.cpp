#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int a[100010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }  
  int neg = 0, pos = 0;
  int an = 0, ap = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] > 0) {
      pos = pos + a[i];
      ap++;
    }
  }
  for (int i = N-1; i >= 0; i--) {
    if (a[i] < 0) {
      neg = neg + a[i];
      an++;
    }
  }
  if (abs(pos) > abs(neg)) {
    cout << max(ap-1, 0) + an + N-1 << endl;
    int last = 0;
    while (last < N && a[last] <= 0) last++;
    for (int i = last + 1; i < N; i++) {
      if (a[i] > 0) {
        cout << last + 1 << " " << i + 1 << endl;
        last = i;
      }
    }
    for (int i = 0; i < N; i++) {
      if (a[i] < 0) {
        cout << last + 1 << " " << i + 1 << endl;
      }
    }
    for (int i = 0; i+1 < N; i++) {
      cout << i + 1 << " " << i + 2 << endl;
    }
  } else {
    cout << max(an-1, 0) + ap + N-1 << endl;
    int last = 0;
    while (last < N && a[last] >= 0) last++;
    for (int i = last + 1; i < N; i++) {
      if (a[i] < 0) {
        cout << last + 1 << " " << i + 1 << endl;
        last = i;
      }
    }
    for (int i = 0; i < N; i++) {
      if (a[i] > 0) {
        cout << last + 1 << " " << i + 1 << endl;
      }
    }
    for (int i = N-1; i-1 >= 0; i--) {
      cout << i + 1 << " " << i << endl;
    }
  }

  return 0;
}