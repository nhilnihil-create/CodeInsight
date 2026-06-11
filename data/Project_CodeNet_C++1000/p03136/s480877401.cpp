#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n, sum = 0, max = 0;
	cin >> n;
	vector<int> l(n);
	rep(i, n) {
		cin >> l[i];
		if(max < l[i]) max = l[i];
		sum += l[i];
	}
	if (max < sum - max) cout << "Yes";
	else cout << "No";
	return 0;
}
