#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
typedef pair<long long , long long> P;
int main() {
	int N, M; cin >> N >> M;
	vector<P>A(N);
	rep(i, N) {
		cin >> A.at(i).first >> A.at(i).second;
	}
	sort(A.begin(), A.end());
	long long ans = 0, num = 0;
	int i = 0;
	while (num < M && i < N) {
		if (M - num <= A.at(i).second) {
			ans += (M - num) * A.at(i).first;
			num = 10000000;
		}
		else {
			ans += (A.at(i).first * A.at(i).second);
			num += A.at(i).second;
		}
		i++;
	}
	cout << ans << endl;
}