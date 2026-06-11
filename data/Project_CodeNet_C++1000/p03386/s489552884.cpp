#include <bits/stdc++.h>
using namespace std;
void f(int a, int b) {for (int i{a}; i <= b; ++i) cout << i << "\n";}
int main()
  {int A, B, K, x, y; cin >> A >> B >> K, x = min(B, A + --K), y = max(A, B - K);
  y <= x ? f(A, B) : (f(A, x), f(y, B));}