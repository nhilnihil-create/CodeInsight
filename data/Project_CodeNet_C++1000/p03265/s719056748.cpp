#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	vector<int> vec(4);
	vector<int> value(4);
	for (int i = 0; i < 4; i++) {
		cin >> x;
		vec.at(i) = x;
	}
	value.at(0) = vec.at(1) + vec.at(2) - vec.at(3);
	value.at(1) = vec.at(2) + vec.at(3) - vec.at(0);
	value.at(2) = vec.at(0) + vec.at(1) - vec.at(3);
	value.at(3) = vec.at(1) + vec.at(2) - vec.at(0);
	for (int i = 0; i < 4; i++) {
		cout << value.at(i) << " ";
	}
}