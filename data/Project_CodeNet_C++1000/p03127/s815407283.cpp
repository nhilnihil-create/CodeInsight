#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int n;
int a[100000];

int main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	
	int g = a[0];
	for (i = 1; i < n; i++) g = gcd(g, a[i]);
	cout << g << endl;
	return 0;
}