#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

vector<int>v;
map<int, int>mp;

int main() {
	bool visited[110];
	int m, k; cin >> m >> k;
	int x_or = 0;
	for (int i = 0; i < (1 << m); i++) {
		v.push_back(i); v.push_back(i);
		if (i != k) x_or ^= i;
	}
	if (k == 0) {
		for (auto&& x : v)cout << x << ' ';
		return 0;
	}
	if (x_or == k) {
		int n = (1 << (m + 1));
		v[n / 2 - 1] = k;
		int j = 0;
		for (int i = 0; i < n / 2 - 1; i++) {
			if (j == k)j++;
			v[i] = j;
			v[n - 2 - i] = j;
			j++;
		}
		v[n - 1] = k;
		for (auto&& x : v)cout << x << ' ';
		return 0;
	}
	cout << -1;
	return 0;
}