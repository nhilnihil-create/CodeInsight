#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<int>xs(n);
	for (int i = 0; i < n; i++)cin >> xs.at(i);
	xs.push_back(x);
	vector<int>ys(m);
	for (int i = 0; i < m; i++)cin >> ys.at(i);
	ys.push_back(y);
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	if (xs.at(n) < ys.at(0))cout << "No War" << endl;
	else cout << "War" << endl;
}