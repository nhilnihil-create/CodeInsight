#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	vector<int> a(n); for(int i = 0; i < n; i++)cin >> a[i];
	vector<int> ans;

	for(int i = 0; i < n; i++) {
		bool res = false;
		for(int j = (int)a.size() - 1; j >= 0; j--) {
			if(a[j] == j + 1) {
				ans.push_back(j + 1);
				a.erase(a.begin() + j);
				res = true;
				break;
			}
		}
		if(!res) {
			cout << -1 << endl;
			return 0;
		}
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < n; i++)cout << ans[i] << endl;
}