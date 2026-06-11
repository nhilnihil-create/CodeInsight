#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv) {
	vector<int> a(4);
	for (int i = 0; i < 4; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9 ? "YES" : "NO") << endl;
}
