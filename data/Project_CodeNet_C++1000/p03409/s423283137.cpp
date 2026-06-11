#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int,int>>a(n), b(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = { -y,x };
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i].first >> b[i].second;
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)a[i].first *= -1;
	sort(b.begin(), b.end());

	int ans = 0;
	vector<bool>b_ok(n, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b_ok[j])continue;
			if (a[i].second < b[j].first && a[i].first < b[j].second) {
				b_ok[j] = true; ans++;
				break;
			}				
		}
	}
	cout << ans << endl;

	return 0;
}