#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, d = 0;
  	cin >> a >> b;
  	for (int c = 1; c <= 3; ++c)
      d |= a * b * c % 2;
  	cout << (d > 0 ? "Yes" : "No") << "\n";
}