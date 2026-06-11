#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;
int N;
int K;
int Q;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K >> Q;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int ans = 2e9;
	for (int z = 0; z < N; z++) {
		int mi = A[z];
		vector<int> buf;
		vector<int> cnds;
		for (int i = 0; i <= N; i++) {
			if (i == N || A[i] < mi) {
				if (int(buf.size()) >= K) {
					int cnt = int(buf.size()) - K + 1;
					nth_element(buf.begin(), buf.begin() + cnt, buf.end());
					cnds.insert(cnds.end(), buf.begin(), buf.begin() + cnt); 
				}
				buf.clear();
			} else {
				buf.push_back(A[i]);
			}
		}
		
		if (int(cnds.size()) >= Q) {
			nth_element(cnds.begin(), cnds.begin() + Q-1, cnds.end());
			ans = min(ans, cnds[Q-1] - mi);
		}
	}
	cout << ans << '\n';

	return 0;
}
