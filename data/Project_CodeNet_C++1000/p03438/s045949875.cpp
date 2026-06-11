
// B - Two Arrays

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int a[10000];
int b[10000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> a[i];
	}

	for (int i=0; i<N; i++) {
		cin >> b[i];
	}

	ll a_rem = 0;
	ll b_need = 0;
	for (int i=0; i<N; i++) {
		if (a[i] < b[i]) {
			a_rem += (b[i] - a[i]) / 2;
		} else {
			b_need += a[i] - b[i];
		}
	}

	string ans;
	if (a_rem >= b_need) ans = "Yes";
	else ans = "No";

	cout << ans << endl;

	return 0;
}