#include <bits/stdc++.h>
using namespace std;
int N, A, B, c[3], P;
int main()
  {cin >> N >> A >> B; while (cin >> P) ++c[P > B ? 2 : P > A];
  cout << *min_element(c, c + 3);}