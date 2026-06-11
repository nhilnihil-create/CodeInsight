#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int prime(int x) {
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return 0;
	return 1;
}

vector<int> ans;

int main() {
	for (int i = 11; i <= 5555; i += 10)
		if (prime(i)) ans.push_back(i);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
	return 0;
}