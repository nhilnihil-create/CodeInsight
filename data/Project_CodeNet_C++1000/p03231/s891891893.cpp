#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  long L = lcm(N, M);
  map<long, char> MA;
  for (long i = 0; i < N; i++) MA[i * (L / N)] = S.at(i);
  for (long i = 0; i < M; i++) if (MA[i * (L / M)] != 0 && MA[i * (L / M)] != T.at(i)) return cout << -1 << "\n", 0;
  cout << L << "\n";
}