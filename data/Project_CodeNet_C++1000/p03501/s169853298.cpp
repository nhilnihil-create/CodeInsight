#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int a;
  int b;

  cin >> n >> a >> b;

  int s;

  if (a * n > b)
    s = b;
  else
    s = a * n;

  cout << s << endl;
}
