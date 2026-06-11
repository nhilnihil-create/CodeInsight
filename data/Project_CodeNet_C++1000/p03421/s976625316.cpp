#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

int main() {
	ll N, A, B;
	cin >> N >> A >> B;
	if (A * B < N) {
		cout << -1 << endl;
		return 0;
	}
	if (A + B - 1 > N) {
		cout << -1 << endl;
		return 0;
	}
	if (B == 1) {
		for (int i = 0;i < A;i++) {
			cout << i + 1 << " ";
		}
		cout << endl;
		return 0;
	}
	
	vector<int> X(N);
	for (int i = 0;i < N;i++) {
		X[i] = i + 1;
	}
	ll Y = (N - A) / (B - 1);
	ll Z = (N - A) % (B - 1);
	for (ll i = 0;i < Y;i++) {
		reverse(X.begin() + B * i, X.begin() + B * (i + 1));
	}
	reverse(X.begin() + B * Y, X.begin() + B * Y + Z + 1);
	for (int i = 0;i < N;i++) {
		cout << X[i] << " ";
	}
	cout << endl;
}