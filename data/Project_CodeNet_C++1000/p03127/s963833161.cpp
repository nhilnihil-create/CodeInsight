#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b > a) {
      int tmp = a;
      a = b;
      b = tmp;
    }
  	if (b == 0) return a;
  	return gcd(b, a % b);
}

int main() {
	int n, a, cgcd;
  	cin >> n >> cgcd;
  	for (int i = 1; i < n; i++) {
      cin >> a;
      cgcd = gcd(cgcd, a);
    }
 	cout << cgcd;
  	return 0;
}