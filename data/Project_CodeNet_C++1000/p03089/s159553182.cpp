#include<bits/stdc++.h>
using namespace std;

vector<int> ans;



int main() {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
	}

	for (int i = 0; i < n; i++) {
		int same = -1;
		for (int i = b.size() - 1; i >= 0; i--) {
			if (i == b[i]) {
				same = i;
				break;
			}
		}
		if (same == -1) {
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(same);
		b.erase(b.begin() + same);
	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < n; i++) {
		cout << ans[i]  + 1 << endl;
	}	
	
	return 0;
}
