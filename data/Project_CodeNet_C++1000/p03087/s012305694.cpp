#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;

	vector <int> num(N);
	int cnt = 0;
	bool aflag = false;
	for (int ii = 0; ii < N; ++ii){
		if (aflag){
			if (S[ii] == 'C'){
				cnt++;
			}
		}
		if (S[ii] == 'A'){
			aflag = true;
		} else {
			aflag = false;
		}
		num[ii] = cnt;
	}

	for (int ii = 0; ii < Q; ++ii){
		int l, r;
		cin >> l >> r;
		l--; r--;
		int ans = num[r] - num[l];
		cout << ans << "\n";
	}

	return 0;
}
