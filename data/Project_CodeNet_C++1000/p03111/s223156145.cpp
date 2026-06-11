#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	vector<int> target(3);
	cin >> n >> target[0] >> target[1] >> target[2];
	vector<int> l(n);
	rep(i,n) cin >> l[i];
	
	int num_rep = pow(4,n);
	int ans = 1e9;
	vector<int> kind(n);
	vector<int> length(3);
	rep(i,num_rep) {
		int tmp = i;
		int mp = 0;
		rep(j,4) length[j] = 0;
		rep(j,n) {
			int r = tmp%4;
			if (r!=3) {
				if (length[r]!=0) mp += 10;
				length[r] += l[j];
			}
			tmp /= 4;
		}
		bool fl = true;
		rep(j,3) if (length[j]==0) fl = false;
		if (fl) {
			rep(j,3) mp += abs(length[j] - target[j]);
			ans = min(mp, ans);
		}
	}
	cout << ans << endl;

	return 0;
}
