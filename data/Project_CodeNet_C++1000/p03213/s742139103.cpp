#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		int num = i;
		for (int j = 2; j * j <= num; j++) {
			while (num % j == 0) {
				v[j]++;
				num /= j;
			}
		}
		if (num > 1) v[num]++;
	}
	int c5 = 0, c3 = 0;
	int c25 = 0;
	int c15 = 0;
	int c75 = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] >= 3) c3++;
		if (v[i] >= 5) c5++;
		if (v[i] >= 15) c15++;
		if (v[i] >= 25) c25++;
		if (v[i] >= 75) c75++;
	}
	// cout << c3 << " " << c5 << " " << c15 << " " << c25 << " " << c75 << endl;
	cout << (c3 - c5) * c5 * (c5 - 1) / 2 + c5 * (c5 - 1) * (c5 - 2) / 2 + c15 * (c15 - 1) + (c5 - c15) * c15 + c25 * (c25 - 1) + (c3 - c25) * c25 + c75 << endl;
}
