#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  char C;
  while (cin >> C) if (C == 'Y') return cout << "Four" << "\n", 0;
  cout << "Three" << "\n";
}