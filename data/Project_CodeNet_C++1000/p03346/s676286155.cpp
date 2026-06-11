#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
int pos [MAX_N];

int main () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }

  int ans = 1, cur = 1;
  for (int i = 2; i <= n; i++) {
    if (pos[i] < pos[i - 1]) {
      cur = 1;
    } else {
      cur++;
    }
    ans = max(ans, cur);
  }

  cout << n - ans << endl;
}
