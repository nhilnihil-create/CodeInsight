#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = a * n;
  cout << (ans < b ? ans : b) << endl;
  return 0;
}