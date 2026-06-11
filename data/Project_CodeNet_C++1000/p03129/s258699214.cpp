#include<iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if ((int)(n * 0.5 + 0.5) >= k) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}