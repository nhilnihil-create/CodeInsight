#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,K;
	cin >> N>>K;
	string S;
	cin >> S;
	vector<int>A;
	int now = -1;
	if ('0' == S[0]) {
		A.push_back(0);
		now++;
	}
	for (int n = 0;n<N;++n) {
		if (0 == n) {
			A.push_back(1);
			now++;
		}
		else {
			if (S[n-1] != S[n]) {
				A.push_back(1);
				now++;
			}
			else {
				A[now]++;
			}
		}
	}
	if ('0' == S[N - 1]) {
		A.push_back(0);
		now++;
	}
	if (A.size()<=2 * K + 1) {
		cout << N<<endl;
		return 0;
	}
	int ans = 0;
	int sum = 0;
	for (int n = 0;n<2 * K + 1;++n) {
		ans += A[n];
	}	
	sum = ans;
	for (int n = 0; 2 * K + 2 + n <= A.size()-1; n += 2) {
		if (2*K+2+n >= A.size()) {
			cout << sum << endl;
			break;
		}
		sum -= A[n];
		sum -= A[n+1];
		sum += A[2*K+1+n];
		sum += A[2*K+2+n];
		ans = max(ans, sum); 
	}
	cout << ans<<endl;
	return 0;
}