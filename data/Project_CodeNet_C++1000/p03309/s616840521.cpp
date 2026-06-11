#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {         
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		ans.push_back(v[i] - (i + 1));
	}
	sort(ans.begin(),ans.end());
	ll res = 0;
	int b = ans[n / 2];
	for (int i = 0; i < n; ++i) {
		res += abs(v[i]  - (b + i + 1));   
	}
	cout << res;
}


//abs(x1 - b - a) + abs(x2 - b -  a - 1)) +  abs(x3 - b - a - 2)) >= 0
