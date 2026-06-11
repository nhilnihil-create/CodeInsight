#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n,cnt=0;
	bool flag = true;;
	cin >> n;
	vector<int>garden(n);
	rep(i, n)cin >> garden[i];
	while (flag) {
		flag = false;
		rep(i, n) {
			if (garden[i] != 0) {
				flag = true;
				garden[i]--;
				for (i = i + 1; i < n; i++) {
					if (garden[i] == 0)break;;
					garden[i]--;
				}
				cnt++;
			}
		}

	}

	cout << cnt << endl;
	return 0;
}

