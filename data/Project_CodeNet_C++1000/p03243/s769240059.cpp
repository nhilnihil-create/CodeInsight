#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int cnt = N / 111;
  if ((N % 111) != 0) cnt++;
  cout << 111 * cnt << endl;
}