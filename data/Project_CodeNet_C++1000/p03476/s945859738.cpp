#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

bool check_prime(int a) {
	for (int i=2; i*i <= a; i++) {
		if (a%i==0) return false;
	}
	return true;
}

int main(int, char**) {
	int a = 100010;
	vector<bool> P;
	vector<int> S;
	P.push_back(false);
	P.push_back(false);
	P.push_back(true);// 2
	S.push_back(0);
	S.push_back(0);
	S.push_back(0);
	int cnt = 0;
	for (int i=3; i<a; i++) {
		if (check_prime(i)) {
			P.push_back(true);
			if (P[(i + 1)/2]) cnt++;
		} else {
			P.push_back(false);
		}
		S.push_back(cnt);
	}
	int q; cin >> q;
	for (int i=0; i<q; i++) {
		int l, r; cin >> l >> r;
		cout << S[r] - S[l - 1] << endl;
	}
	return 0;
}