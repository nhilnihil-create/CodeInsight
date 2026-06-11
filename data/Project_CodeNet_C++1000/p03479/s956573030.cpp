#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	long x, y;
	cin >> x >> y;
	vector<long> a;
	a.push_back(x);
	int i = 2;
	while (true) {
		if (a.back() > y / i) break;
		long nxt = a.back() * i;
		bool flag = false;
		for (auto q : a) {
			if (nxt % q != 0) flag = true;
		}
		if (flag) {
			i++;
			continue;
		}
		a.push_back(nxt);
		i = 2;
	}
	cout << a.size() << endl;
}