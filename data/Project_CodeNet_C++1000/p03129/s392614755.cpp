#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  bool can = (n + 1) / 2 >= k;
  if (can)
    puts("YES");
  else
    puts("NO");
}