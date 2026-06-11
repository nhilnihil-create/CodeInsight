#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	map<int,int> ind;
	map<int,int> cnt;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		ind[v[i]] = -1;
		//ind[v[i]].push_back(i);
		//cnt[v[i]]++;
	}
	vector<int> a = v;
	sort(a.begin(),a.end());
	for (int i = 0; i < n; ++i) {
		if (ind[a[i]] == -1) {
			ind[a[i]] = i;
		}
	}
	vector<int> ans(n);
	for (int i = 0;i < n; ++i) {
		int index = ind[v[i]] + cnt[v[i]];
		cnt[v[i]]++;
		if (index >= n / 2) {
			ans[i] = a[(n / 2) - 1];
		}else {
			ans[i] = a[n / 2];
		}
		//. . . . . . // (n/2) 
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << endl;
	} 
}


