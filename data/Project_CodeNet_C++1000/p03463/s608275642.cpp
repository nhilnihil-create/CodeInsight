#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  
  if(abs(a - b) % 2) cout << "Borys" << endl;
  else cout << "Alice" << endl;
}