#include <bits/stdc++.h>
using namespace std;
int main()
  {int c[2], K; cin >> c[0] >> c[1] >> K;
  for (int i{}; K--; i = !i) c[i] /= 2, c[!i] += c[i];
  cout << c[0] << " " << c[1];}