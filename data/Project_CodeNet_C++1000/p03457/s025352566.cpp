#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;



int main() {
	
	int N;
	cin >> N;

	vector<int> t(100010, 0); vector<int> x(100010, 0); vector<int> y(100010, 0);

	for (int i = 0; i < N; i++) {
		cin >> t.at(i + 1);
		cin >> x.at(i + 1);
		cin >> y.at(i + 1);
	}

	bool flag = true;

	for (int i = 0; i < N; i++) {
		int a = abs(x.at(i + 1) - x.at(i)) + abs(y.at(i + 1) - (y.at(i)));
		int b = t.at(i + 1) - t.at(i);

		if (a > b) flag = false;
		if (a % 2 != b % 2) flag = false;
	}

	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}