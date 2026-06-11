#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, D, X;
	cin >> r >> D >> X;
	vector<int> vec(10);
	for (int i = 0; i < 10; i++) {
		vec.at(i) = r * X - D;
		X = vec.at(i);
	}
	for (int j = 0; j < 10; j++) {
		cout << vec.at(j) << endl;
	}
}