#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	map<int, int> d;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		d[a]++;
	}
	cin >> m;
	map<int, int> t;
	for (int i = 0; i < m; i++) {
		cin >> a;
		t[a]++;
	}

	for (auto & i : t) {
		if (i.second > d[i.first]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}