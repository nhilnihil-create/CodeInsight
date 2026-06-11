#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >>b;
	vector<int>rank(3,0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x <= a)rank.at(0)++;
		else if (x <= b)rank.at(1)++;
		else rank.at(2)++;
	}
	sort(rank.begin(), rank.end());
	cout << rank.at(0) << endl;
}