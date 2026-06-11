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

signed main() {
	string S;
	cin >> S;

	int cnt[3] = { 0, 0, 0 };
	rep(i, S.size()) {
		cnt[S[i] - 'a']++;
	}

	int minV = 100000000;
	int maxV = 0;
	rep(i, 3) {
		minV = min(minV, cnt[i]);
		maxV = max(maxV, cnt[i]);
	}

	if (maxV - minV >= 2) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}


    return 0;
}
