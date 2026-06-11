#include <bits/stdc++.h>
using namespace std;

int A[200055];

int N;

bool isp(int X) {
	map<int, int> PQ;
	for(int i = 2; i <= N; i++) {
		if(A[i-1] < A[i]) continue;
		for(; !PQ.empty();) {
			auto it = prev(PQ.end());
			if(it->first < A[i]) break;
			PQ.erase(it);
		}
		for(int x = A[i]-1;; x--) {
			if(x < 0) return false;
			int k = 0;
			auto it = PQ.find(x);
			if(PQ.end() != it) {
				k = it->second;
				PQ.erase(it);
			}
			k++;
			if(k < X) {
				PQ.insert({x, k});
				break;
			}
		}
	}
	return true;
}

int getAns() {
	int s = 2, e = N; for(int m; s < e;) {
		m = (s+e) >> 1;
		if(isp(m)) e = m;
		else s = m+1;
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];

	{
		bool flag = true;
		for(int i = 1; i < N; i++)
			flag &= A[i] < A[i+1];
		if(flag) {
			puts("1");
			return 0;
		}
	}

	cout << getAns() << endl;
	return 0;
}