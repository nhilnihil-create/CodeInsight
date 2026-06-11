#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	int a1, b1, a2, b2, a3, b3;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	vector<int> v = { a1, b1, a2, b2, a3, b3 };
	map<int, int> mp = { {1,0},{2,0},{3,0},{4,0} };
	for (const auto& item : v) mp[item]++;
	for (const auto& item : mp) {
		if (item.second == 3) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
