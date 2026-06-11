#include <iostream>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 105;

int arr [MAX_N];
int del [MAX_N];
int inv [MAX_N];
int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    inv[i] = i - arr[i];
    if (inv[arr[i]] < 0) {
      failure();
    }
  }

  for (int i = n; i >= 1; i--) {
    int rz = -1;
    for (int j = 1; j <= n; j++) {
      if (!del[j] && inv[j] == 0) {
	rz = j;
      }
    }

    if (rz == -1) failure();
    ans[i] = arr[rz];
    del[rz] = 1;
    for (int j = rz + 1; j <= n; j++) {
      inv[j]--;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (ans[i] > i) failure();
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
}
