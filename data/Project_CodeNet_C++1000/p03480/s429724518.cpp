#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string h;
	cin >> h;
	unsigned long long ans = h.length();
	for (unsigned long long i = 0; i < h.length() - 1; ++i) {
		if (h[i] != h[i + 1]) {
			ans = min(ans, max(i + 1, h.length() - i - 1));
		}
	}
	cout << ans << endl;
}