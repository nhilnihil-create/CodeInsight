#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int takahashi_count = 0;
  takahashi_count += a-1;

  if (a <= b) {
    takahashi_count ++;
  }
  cout << takahashi_count << endl;
}
