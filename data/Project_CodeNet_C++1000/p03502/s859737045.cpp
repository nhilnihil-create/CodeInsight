#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	int fx = 0;
	int tmp = n;
	while (tmp) {
		fx += tmp % 10;
		tmp /= 10;
	}
	if (n % fx == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}