#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;

int main() {
  cin >> n >> a >> b;
  if (a - 1 == 0 && a + 1 == b)
  	return cout << "Borys" << '\n',0;
  b -= a;
  b--;
  if (b % 2)
    return cout << "Alice" << '\n', 0;
  cout << "Borys" << '\n';
 	return 0; 
}