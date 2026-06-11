#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int s = N - N / 1000 * 1000;

  if(s %111 == 0 || N / 10 % 111 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}