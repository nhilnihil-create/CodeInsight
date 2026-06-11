#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int ans = 0;
	int i = 0;
	while (i < 3) {
		if (s[i] == '1')
			ans++;
		i++;
	}
	cout << ans << "\n";
}