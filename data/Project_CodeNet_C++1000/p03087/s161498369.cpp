#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;

	int AC[N];
	AC[0] = 0;
	for(int i = 1; i < N; i++) {
		AC[i] = AC[i - 1];
		if(S[i - 1] == 'A' && S[i] == 'C') AC[i]++;
	}

	for(int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << AC[r] - AC[l] << "\n";
	}
	return 0;
}
