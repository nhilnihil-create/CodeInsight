#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  int k = 0;
  while (n >= 4 && k < 3) {
    if (n % 4 == 0) {
      cout << "Yes";
      return 0;
    }
    n -= 7;
    k++;
  }
  if (n == 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
