#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int s; cin >> s;

	const int p = 147483647;
	vector<int> num(p, 0);

	int ans;
	int a_prev;
	int a_now = s;
	int i = 1;
	while (true) {

		if (i == 1) {
			a_now = s;
		}
		else {
			a_prev = a_now;
			if (a_prev % 2 == 0) {
				a_now = a_prev / 2;
			}
			else {
				a_now = a_prev * 3 + 1;
			}
		}

		if (num[a_now] == 1) break;
		else num[a_now]++;
		
		i++;
	}

	cout << i << endl;
	return 0;
}