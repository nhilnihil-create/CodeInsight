#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &a : A) cin >> a;
	int minv = INT_MAX, maxv = INT_MIN;
	int minp = -1, maxp = -1;
	for(int i=0;i<N;i++) {
		if(minv > A[i]) {
			minp = i;
			minv = A[i];
		}
		if(maxv < A[i]) {
			maxp = i;
			maxv = A[i];
		}
	}
	vector<pair<int,int>> ans;
	if(abs(minv) < abs(maxv)) {
		for(int i=0;i<N;i++) {
			if(A[i] < 0) {
				ans.push_back({maxp ,i});
				A[i] += maxv;
			}
		}
		for(int i=1;i<N;i++) {
			A[i] += A[i-1];
			ans.push_back({i-1, i});
		}
	} else {
		for(int i=0;i<N;i++) {
			if(A[i] > 0) {
				ans.push_back({minp ,i});
				A[i] += minp;
			}
		}
		for(int i=N-2;i>=0;i--) {
			A[i] += A[i+1];
			ans.push_back({i+1, i});
		}
	}
	cout << ans.size() << endl;
	for(auto &a : ans) cout << a.first+1 << " " << a.second+1 << endl;

	return 0;
}