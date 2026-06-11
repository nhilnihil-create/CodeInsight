#include <bits/stdc++.h>

using namespace std;

int main () {

  int a, b, c, d, e, k;
  bool ans = true;
  cin >> a >> b >> c >> d >> e >> k;

  int arr[] = { a, b, c, d, e };

  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (arr[j] - arr[i] > k) {
        ans = false;
        break;
      }
    }
  }

  if (ans) {
    cout << "Yay!" << endl; 
  } else {
    cout << ":(" << endl;
  }
  

  return 0;
}