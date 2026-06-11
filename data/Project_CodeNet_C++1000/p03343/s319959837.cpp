#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
typedef long long ll;
#define int long long

bool possible(const vector<int> &A, int K, int Q, int l, int u) {
	int p = 0;
	int sum = 0;

	while(p < A.size()) {
		int q = p;
		int cnt = 0;
		while(q < A.size() && l <= A[q]) {
			if (A[q] <= u) {
				++cnt;
			}
			q++;
		}
		if (q - p >= K) sum += min(cnt, (q - p) - K + 1);

		p = q + 1;
	}

	return sum >= Q;
}

signed main(){
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	int res = (int)(1e9 + 10);
	for(int i = 0; i < N; ++i) {
		int l = 0, u = (int)1e+9 + 10;
		while(u - l > 1) {
			int c = (u + l) / 2;
			if(possible(A, K, Q, A[i], c)) {
				u = c;
			} else {
				l = c;
			}
		}
		if (u < 1e+9 + 5) res = min(res, u - A[i]);
	}
	cout << res << endl;
	return 0;
}
