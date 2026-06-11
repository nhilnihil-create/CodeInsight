#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  LL a, b;
  cin >> a >> b;
  LL fee;
  if (a >= 13) fee = b;
  else if (a >= 6) fee = b / 2;
  else fee = 0;

  cout << fee << endl;
}

