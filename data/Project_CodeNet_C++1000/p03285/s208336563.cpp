#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  
  for (int k = 0; k <= 100/4; k++) {
    for (int d = 0; d <= 100/7; d++) {
      if (k*4 + d*7 == N) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
