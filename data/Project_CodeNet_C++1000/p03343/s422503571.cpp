#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <climits>
#include <functional>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rep1(i,n) for(int i=1;i<=(int)n;++i)
#define all(a) begin(a),end(a)

const int inf = 1e9 + 10;

int N,K,Q;
vector<int> A;

int f(int x)
{
	vector<vector<int>> arr;

	{
		vector<int> cur;
		rep(i, N) {
			if (A[i] < x) {
				if (cur.size() >= K) arr.push_back(cur);
				cur = vector<int>();
			} else {
				cur.push_back(A[i]);
			}
		}

		if (cur.size() >= K) {
			arr.push_back(cur);
			cur = vector<int>();
		}
	}

	for (vector<int> &a : arr) sort(all(a));

	vector<int> cand;

	for (vector<int> &a : arr) {
		for (int i = 0; i <= (int)a.size() - K; ++i) {
			cand.push_back(a[i]);
		}
	}

	if (cand.size() < Q) return inf;

	sort(all(cand));

	return cand[Q-1] - cand[0];
}

signed main()
{
	cin >> N >> K >> Q;
	A.resize(N);
	rep(i, N) cin >> A[i];

	int ans = inf;

	rep(i, N) {
		ans = min(ans, f(A[i]));
	}

	cout << ans << endl;
}
