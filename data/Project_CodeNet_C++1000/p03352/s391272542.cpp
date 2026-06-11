#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x; cin >> x;
	const int b_max = 100;
	const int p_max = 10;
	vector<int> c;
	for (int b = 1; b <= b_max; b++) {
		for (int p = 2; p <= p_max; p++) {
			c.push_back(pow(b, p));
		}
	}
	sort(c.begin(), c.end());
	int index = 0;
	int tmp;
	while (true) {
		tmp = c[index];
		if (x < tmp) break;
		index++;
	}
	cout << c[index - 1] << endl;
	return 0;
}