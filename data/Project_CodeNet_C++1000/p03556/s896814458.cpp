#include<iostream>
using namespace std;
int main() {
	unsigned int n;
	cin >> n;
	unsigned int i;
	for ( i = 0; i < n+9; i++) {
		if (i * i > n) break;
	}
	cout << (i - 1) * (i - 1);

}