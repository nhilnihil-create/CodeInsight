#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b = 0;
  cin >> N >> a >> b;
  if (a * N > b)
    cout << b << endl;
  else
    cout << a * N << endl;
}
