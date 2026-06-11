#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int num = 1; num <= N; num++) {
		if (num % 2 == 0) continue;
		int count = 0;
		for (int i = 1; i <= N; i++) {
			if (num % i == 0) count++;
		}
		if (count == 8) ans++;
	}
	cout << ans << endl;
	return 0;
}