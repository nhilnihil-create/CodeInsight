#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> b(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	deque<int> a;

	while (b.size() != 1) {
		for (int i = b.size()-1; i >= 1; i--) {
			if (b[i] == i) {
				a.push_front(b[i]);
				b.erase(b.begin() + i);
				break;
			}
			if (i == 1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a.front() << endl;
		a.pop_front();
	}

	return 0;
}