#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	vector<int> b(n);
	for (int i=0; i<n; i++) cin >> b[i];

	vector<int> ret;
	for (int i=0; i<n; i++) {
		int it = -1;
		for (int j=0; j< n- i; j++) {
			if (b[j] == j + 1) it = j;
		}
		if (it==-1) {
			cout << -1 << endl;
			return 0;
		} else {
			ret.push_back(it + 1);
			b.erase(b.begin() + it);
		}
	}
	
	for (int i=n-1; i>-1; i--) {
		cout << ret[i] << endl;
	}
	return 0;
}