#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

struct range {
	int l;
	int r;
	int num;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	R = N;
	L = 0;
	while (R - L > 1) {
		long long int mid = (R + L + 1) / 2;
		stack<range>st;
		st.push({ 1,v[0],1 });
		bool flag = true;
		for (int i = 1; i < N; i++) {
			if (v[i] > st.top().r) {
				st.push({ st.top().r + 1,v[i],1 });
				continue;
			}
			while (v[i] < st.top().l)st.pop();
			auto box = st.top();
			if (box.num != mid) {
				st.pop();
				if (box.l != v[i]) {
					st.push({ box.l,v[i] - 1,box.num });
				}
				st.push({ v[i],v[i],box.num + 1 });
				continue;
			}
			while (!st.empty() && st.top().num == mid) {
				st.pop();
			}
			if (st.empty()) {
				flag = false;
				break;
			}
			box = st.top();
			st.pop();
			if (box.l != box.r) {
				st.push({ box.l,box.r - 1,box.num });
			}
			st.push({ box.r,box.r,box.num + 1 });
			if (box.r != v[i]) {
				st.push({ box.r + 1, v[i], 1 });
			}
		}
		if (flag)R = mid;
		else L = mid;
	}
	cout << R << endl;
	return 0;
}
