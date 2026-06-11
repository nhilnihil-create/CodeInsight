#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int N,Q;
	cin >> N >> Q;
	string S;
	cin >> S;
	vector< int > cnt(N+1, 0);
	for (int i=1; i<N; i++) {
		cnt[i+1] = cnt[i];
		if (S[i] == 'C' && S[i-1] == 'A') cnt[i+1]++;
	}
	// for (
	for (int i=0; i<Q; i++) {
		int L,R;
		cin >> L >> R;
		cout << cnt[R] - cnt[L] << '\n';
	}
	return 0;
}
