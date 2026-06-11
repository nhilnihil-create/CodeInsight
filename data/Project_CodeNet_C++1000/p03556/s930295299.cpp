#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, i = 0, ans = 0;
  cin >> N;
  while (ans <= N) {
    i++;
    ans = i * i;
  }
  cout << (i - 1) * (i - 1) << endl;
}