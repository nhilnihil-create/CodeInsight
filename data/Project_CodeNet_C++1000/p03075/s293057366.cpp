#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;

  int temp[5] = {a, b, c, d, e};
  bool flag = true;

  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (temp[j] - temp[i] > k) {
        flag = false;
      }
    }
  }

  if (flag) {
    cout << "Yay!" << endl;
  } else {
    cout << ":(" << endl;
  }
}
