#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n); for (auto&& x : a)cin >> x;
	int mini = 10000000000, maxi = 0;
	for (auto x : a) {
		if (x < mini)mini = x;
		if (x > maxi)maxi = x;
	}
	cout << maxi - mini << endl;

	return 0;
}