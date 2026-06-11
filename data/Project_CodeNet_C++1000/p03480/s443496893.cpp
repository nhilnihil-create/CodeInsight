
// D - Wide Flip

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	int N = S.size();

	int l = (N+1) / 2;
	for (int i=(N-1)/2; i<N-1; i++) {
		if (S[i] == S[i+1]) l++;
		else break;
	}

	int r = (N+1) / 2;
	for (int i=N/2; i>0; i--) {
		if (S[i] == S[i-1]) r++;
		else break;
	}

	cout << min(l, r) << endl;

	return 0;
}