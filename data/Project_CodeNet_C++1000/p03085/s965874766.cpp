#include <bits/stdc++.h>
using namespace std;

int main() {
  char C;
  cin >> C;
  cout << ((C == 'A') ? 'T' : (C == 'T') ? 'A' : (C == 'C') ? 'G' : 'C') << "\n";
}