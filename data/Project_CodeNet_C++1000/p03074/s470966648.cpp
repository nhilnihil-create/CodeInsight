
// D - Handstand

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, K;
	string S;
	cin >> N >> K;
	cin >> S;

	vector<int> one;
	vector<int> zero;
	bool counting_one = true;
	int cnt = 0;
	for (int i=0; i<N; i++) {
		if (counting_one) {
			if (S[i] == '1') {
				cnt++;
			} else {
				one.push_back(cnt);
				cnt = 0;
				counting_one = false;
				i--;
			}
		} else {
			if (S[i] == '0') {
				cnt++;
			} else {
				zero.push_back(cnt);
				cnt = 0;
				counting_one = true;
				i--;
			}
		}
	}

	if (one.size() == 0 || zero.size() == 0) {
		cout << N << endl;
		return 0;
	}

	if (S[N-1] == '0') {
		one.push_back(0);
		zero.push_back(cnt);
	} else {
		one.push_back(cnt);
	}

	/*
	// **** debug ****
	for (int o : one) { cout << o << " "; }
	cout << endl;
	for (int z : zero) { cout << z << " "; }
	cout << endl;
	*/

	int t = one[0];
	int l = 0;
	int r = 1;

	// initialize
	while(1) {
		t += zero[r-1];
		t += one[r];
		if (r == one.size() - 1) break;
		if (r == K) break;
		r++;
	}

	int ans = 0;
	while(1) {
		ans = max(ans, t);
		//cout << r << " " << t << endl; // **** debug ****

		t -= one[l];
		t -= zero[l];
		l++;

		if (r == one.size() - 1) break;

		r++;
		t += zero[r-1];
		t += one[r];
	}

	cout << ans << endl;

	return 0;
}