#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  for (int i = 0; i <= N / 7; ++i) if ((N - 7 * i) % 4 == 0) {puts("Yes"); return 0;}
  puts("No");}