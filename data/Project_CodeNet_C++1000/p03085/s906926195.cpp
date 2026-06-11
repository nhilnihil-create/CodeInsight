#include <bits/stdc++.h>
using namespace std;
int main() {
  char b; cin >> b;
  cout << (b == 'A' ? 'T' : b == 'C' ? 'G' : b == 'G' ? 'C' : b == 'T' ? 'A' : ' ');
}