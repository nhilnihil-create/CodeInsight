#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  map<int, int> m;
  for (int i = 0; i < 4; ++i) {
    int n;
    cin >> n;
    m[n]++;
  }

  if (m[1] == 1 && m[7] == 1 && m[9] == 1 && m[4] == 1) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}


