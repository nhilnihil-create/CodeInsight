#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  int i = 1;
  while (pow(i, 2) <= N) i++;

  cout << (i - 1) * (i - 1) << endl;
}