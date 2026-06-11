#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;

typedef pair<int, int> pii;

int main() {
	int n, cMax;
	cin >> n >> cMax;

	vector<priority_queue<pii, vector<pii>, greater<pii>>> p(cMax);
	for (int i = 0; i < n;i++) {
		int s, t, c;
		cin >> s >> t >> c;
		c--;
		p[c].push(make_pair(s, t));
	}


	
	vector<int> sum(100000 * 2 + 2);
	for (int i = 0; i < cMax;i++) {
		vector<int> active(100000 * 2 + 2);


		while (!p[i].empty()) {
			int s = p[i].top().first;
			int t = p[i].top().second;
			p[i].pop();
			active[s * 2 - 1]++;
			active[t * 2]--;
		}

		for (int i = 1; i < 100001 * 2;i++) {
			active[i] += active[i - 1];
		}
		for (int i = 0; i < 100001 * 2;i++) {
			if (active[i] > 0) {
				sum[i]++;
			}
		}

	}
	int ans = 0;
	for (int i = 0; i < 200002;i++) {
		ans = max(ans, sum[i]);
	}
	
	cout << ans << endl;
}
