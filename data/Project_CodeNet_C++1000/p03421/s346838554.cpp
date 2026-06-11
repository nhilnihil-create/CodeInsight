#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;
int main() {
	ll N;
	ll A, B;
	cin >> N >> A >> B;
	if (A + B - 1 > N || N > A*B) {
		cout << -1 << endl;
		return 0;
	}
	vector<ll> v;
	int cnt = N - (A + B - 1);
	for (int i = 1; i <= A; i++) v.push_back(A*(B - 1) + i);
	for (int i = B - 2; i >= 0; i--) {
		v.push_back(A*i + 1);
		for (int j = 2; j <= A; j++) {
			if (cnt == 0) break;
			v.push_back(A*i + j);
			cnt--;
		}
	}
	vector <ll> s = v;
	sort(s.begin(), s.end());
	for (int i = 0; i < v.size(); i++) v[i] = lower_bound(s.begin(), s.end(), v[i]) - s.begin() + 1;
	cout << v[0];
	for (int i = 1; i < v.size(); i++) cout << " " << v[i];
	cout << endl;
}