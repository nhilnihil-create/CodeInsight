#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int x = n + 1;
	if (n % 2 == 1)x--;
	vector<pair<int, int>>ans;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (i + j == x)continue;
			else ans.push_back({ i,j });
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)cout << ans.at(i).first << " " << ans.at(i).second << endl;
}