#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	string S;
	cin >> S;
	int ans = 1000;
	for (int i = 0; i < (int)S.size() - 2; i++) {
		int num = (S[i] - '0') * 100 + (S[i + 1] - '0') * 10 + S[i + 2] - '0';
		int diff = abs(num - 753);
		ans = min(ans, diff);
	}
	cout << ans << endl;
	return 0;
}