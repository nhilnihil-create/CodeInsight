#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	int ans;
	for (int x = 111; x <= 999; x += 111) {
		if (N == x) {
			ans = x;
			break;
		}
		if (N < x) {
			ans = x;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}