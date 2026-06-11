#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;

int main(){
	int N, a;
	cin >> N;
	int mn = MOD, mx = -MOD, mni = 0, mxi = 0;
	for (int i = 0;i < N;i++) {
		cin >> a;
		if (mn > a) mn = a, mni = i;
		if (mx < a) mx = a, mxi = i;
	}
	if (mn >= 0) {
		cout << N - 1 << endl;
		for (int i = 1;i < N;i++)
			cout << i << " " << i + 1 << endl;
	}
	else if (mx <= 0) {
		cout << N - 1 << endl;
		for (int i = N;i > 1;i--)
			cout << i << " " << i - 1 << endl;
	}
	else if (-mn > mx) {
		cout << N * 2 - 2 << endl;
		for (int i = 0;i < N;i++) {
			if (i != mni) cout << mni + 1 << " " << i + 1 << endl;
		}
		for (int i = N;i > 1;i--) {
			cout << i << " " << i - 1 << endl;
		}
	}
	else {
		cout << N * 2 - 2 << endl;
		for (int i = 0;i < N;i++) {
			if (i != mxi) cout << mxi + 1 << " " << i + 1 << endl;
		}
		for (int i = 1;i < N;i++) {
			cout << i << " " << i + 1 << endl;
		}
	}
}