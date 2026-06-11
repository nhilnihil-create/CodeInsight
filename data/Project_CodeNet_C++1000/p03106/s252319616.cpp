#include <bits/stdc++.h>
using namespace std;
int main()
  {int A, B, K, c{}; cin >> A >> B >> K;
  for (int i{min(A, B)}; i > 0; --i)
    {c += !(A % i + B % i);
    if (c == K) cout << i, exit(0);}}