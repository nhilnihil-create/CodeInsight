#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	int n, k;
	cin >> n >> k;
	//9ll inf = 1e18;
	set<int> s;
	int inf = 1e9 + 7;
	vector<int> v(n + 1);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	    v[x]++;
	}
	for (int i = 0; i <= n; ++i) {
		if (v[i] == 0) 
			v[i] = inf;
	}
	if (k >= (int)s.size()) {
		cout << 0;
		return 0;
	}
	sort(v.begin(),v.end());
	//for (int i = 0; i <= n; ++i) {
		//cout << v[i] << " ";
	//}
	int p = (int)s.size() - k;
	int ans = 0;
	for (int i = 0; i < p; ++i) {
		ans += v[i];
	}
	cout << ans;
}




