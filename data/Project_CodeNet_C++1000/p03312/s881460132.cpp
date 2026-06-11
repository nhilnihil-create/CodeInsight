#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(),(a).end()

int main() {
	int N; cin >> N;
	vector<ll> left(N);
	vector<ll> right(N);
	vector<ll> A(N);
	for (int i = 0;i < N;i++)
		cin >> A[i];
	for (int i = 0;i < N;i++) {
		left[i] = A[i];
		if (i)
			left[i] += left[i - 1];
	}
	for (int i = 0;i < N;i++) {
		right[i] = A[N - 1 - i];
		if (i)
			right[i] += right[i - 1];
	}
	ll x, y;
	ll cp1,cp3;
	vector<vector<ll>> T(4);
	for (int i = 1;i < N - 2;i++) {
		x = left[i];
		//cout << x << endl;
		auto it1 = upper_bound(all(left), x / 2);
		auto it2 = it1;
		if (it1 != left.begin()) {
			it1--;
		}
		y = right[N - 2 - i];
		//cout << y << endl;
		auto it3 = upper_bound(all(right), y / 2);
		auto it4 = it3;
		if (it3 != right.begin()) {
			it3--;
		}
		if (abs(x - *it1 - *it1) > abs(x - *it2 - *it2)) {
			T[0].push_back(*it2);
			T[1].push_back(x - *it2);
		}
		else {
			T[0].push_back(*it1);
			T[1].push_back(x - *it1);
		}
		if (abs(y - *it3 - *it3) > abs(y - *it4 - *it4)) {
			T[3].push_back(*it4);
			T[2].push_back(y - *it4);
		}
		else {
			T[3].push_back(*it3);
			T[2].push_back(y - *it3);
		}
	}
	ll ans = -1, cp;
	for (int i = 0;i < T[0].size();i++) {
		cp = 0;
		cp += max({ T[0][i],T[1][i],T[2][i],T[3][i] });
		cp -= min({ T[0][i],T[1][i],T[2][i],T[3][i] });
		//cout << cp << endl;
		if (ans + 1) {
			ans = min(ans, cp);
		}
		else {
			ans = cp;
		}
	}
	cout << ans << endl;
}