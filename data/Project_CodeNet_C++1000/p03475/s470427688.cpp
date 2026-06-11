#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>a(n-1, vector<int>(3));
	for (int i = 0; i < n-1; i++)cin >> a.at(i).at(0) >> a.at(i).at(1) >> a.at(i).at(2);
	for (int i = 0; i < n - 1; i++) {
		int ans = a.at(i).at(1) + a.at(i).at(0);
		for (int j = i+1; j < n -1 ; j++) {
			if (ans <= a.at(j).at(1)) ans = a.at(j).at(1) + a.at(j).at(0);
			else {
				int gap = (ans - a.at(j).at(1)) % a.at(j).at(2);
				if (gap == 0)gap = a.at(j).at(2);
				ans = ans + a.at(j).at(2) - gap + a.at(j).at(0);
			}
		}
		cout << ans << endl;
	}
	cout << 0 << endl;
}
