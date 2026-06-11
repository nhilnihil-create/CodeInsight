#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a + b <= 16 && a <= 8 && b <= 8)
    cout << "Yay!\n";
  else
    cout << ":(\n";  
  return 0;
}