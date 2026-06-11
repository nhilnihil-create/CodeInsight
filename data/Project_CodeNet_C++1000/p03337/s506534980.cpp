#include <bits/stdc++.h>

using namespace std;

int main () {
  int A, B, ans;

  cin >> A >> B;

  int arr[3] = {A + B, A - B, A * B};
 
  if (arr[0] >= arr[1] && arr[0] >= arr[2]) {
    ans = arr[0];
  } else if (arr[1] >= arr[0] && arr[1] >= arr[2]) {
    ans = arr[1];
  } else {
    ans = arr[2];
  }

  cout << ans << endl;

  return 0;
}