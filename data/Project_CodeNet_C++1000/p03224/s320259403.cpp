#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

int process(vector<vector<int>> &ret, int pt, int base, int h, int w) {
	if (h == 1) {
	} else if (h == 2) {
		rep(y, 2) {
			ret[pt + y].push_back(base);
		}
	} else {
		vector<int> v;
		int bbase = base;
		rep(y, 3) {
			ret[pt + y].push_back(base++);
			rep(x, w - 2) {
				v.push_back(base);
				ret[pt + y].push_back(base++);
			}
			if (y < 2) ret[pt + y].push_back(base);
			else ret[pt + y].push_back(bbase);
		}
		REP(y, 3, h - 1) {
			rep(x, 3) {
				ret[pt + y].push_back(v[x * (w - 2) + (y - 3)]);
			}
		}
		return base;
	}
	return INT_MAX;
}

signed main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << "Yes" << endl;
		cout << "2" << endl;
		cout << "1 1" << endl;
		cout << "1 1" << endl;
		return 0;
	}

	bool ok = false;
	int W, H;
	REP(i, 2, 10000) {
		int tmp = i * (i + 1);
		if (tmp > 2 * N) break;
		if (tmp == 2 * N) {
			ok = true;
			W = i;
			H = i + 1;
			break;
		}
	}
	if (!ok) {
		cout << "No" << endl;
		return 0;
	}

	vector<vector<int>> ret(H);
	rep(i, H) ret[i];

	int pt = 0;
	int base = 1;
	while (pt < H) {
		base = process(ret, pt, base, H - pt, W - pt);
		pt += 3;
	}

	cout << "Yes" << endl;
	cout << ret.size() << endl;
	for (auto &v : ret) {
		cout << v.size();
		for (auto &num : v) cout << " " << num;
		cout << endl;
	}

    return 0;
}
