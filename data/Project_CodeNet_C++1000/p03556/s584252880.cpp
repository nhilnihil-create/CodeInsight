#include <bits/stdc++.h>
using namespace std;

int main () {
  int N; cin >> N;
  int i = 0;
  while (i * i <= N) i++;
  i--;
  cout << i * i << endl;
}