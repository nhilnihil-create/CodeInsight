#include<iostream>
using namespace std;
using ll = long long;

int main() {
	int s;
	cin >> s;

	if (s == 1 || s == 2) {
		cout << 4 << endl;
		return 0;
	}


	int ans = 1;

	while (s != 4) {
		if (s % 2)s = s * 3 + 1;
		else s /= 2;

		ans++;
	}

	cout << ans + 3 << endl;
	
}