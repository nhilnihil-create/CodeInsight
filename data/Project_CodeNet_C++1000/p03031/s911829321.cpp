#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> s(M);
	for (int i=0;i<M;i++) {
		int k;
		cin >> k;
		vector<int> tmp(k);
		for (int j=0;j<k;j++) {
			cin >> tmp[j];
		}
		s[i] = tmp;
	}

	vector<int> p(M);
	for (int i=0;i<M;i++) {
		cin >> p[i];
	}

	int ans = 0;
	for (int i=0;i<(1<<N);i++) {
		vector<int> arr(N);
		int tmp = i;
		for (int j=0;j<N;j++) {
			arr[j] = tmp%2;
			tmp /= 2;
		}

		bool flag = true;
		for (int i=0;i<M;i++) {
			int k = s[i].size();
			int cnt = 0;
			for (int j=0;j<k;j++) {
				cnt += arr[s[i][j]-1];
			}
			if (cnt%2 != p[i]) flag = false;
		}
		if (flag) {
			ans++;
		}
	}
	cout << ans << endl;
}