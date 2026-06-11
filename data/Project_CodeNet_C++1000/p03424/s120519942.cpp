#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool flag = false;
  for (int i = 0; i < N; i++){
    char s;
    cin >> s;
    if (s == 'Y') flag = true;
  }
  if (flag) cout << "Four" << endl;
  else cout << "Three" << endl;
}