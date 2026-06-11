#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n); for (auto&& x : a)cin >> x;
	sort(a.begin(), a.end());
	cout << a[n - 1] - a[0] << endl;

	return 0;
}