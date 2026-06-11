#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

void failure () {
  cout << -1 << endl;
  exit(0);
}

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i] -= i;
  }

  int mn = n - 1;
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] > 0) failure();
    if (-arr[i] == mn) {
    } else if (-arr[i] < mn) {
      ans += i + arr[i];
      mn = -arr[i];
    } else {
      failure();
    }
  }

  cout << ans << endl;
}
