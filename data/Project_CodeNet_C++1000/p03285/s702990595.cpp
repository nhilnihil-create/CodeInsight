#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  bool res = false;
  for (int i = 0; i <= (100 / 4); ++i) {
    for (int j = 0; j <= (100 / 7); ++j) {
      if (n == (i * 4 + j * 7)) res = true;
    }
  }
  cout << (res ? "Yes" : "No") << endl;
}