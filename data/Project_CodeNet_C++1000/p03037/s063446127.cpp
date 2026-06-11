#include <bits/stdc++.h>
#define	rep(i,n) for (int i =0; i < (n); ++i)
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> L(m);
	vector<int> R(m);
	rep(i,m) cin >> L[i] >> R[i];
	sort(R.begin(), R.end());
	sort(L.begin(), L.end(),greater<int>());
	int sms = R[0];
	int ler = L[0];
//	cout << sms << endl;
//	cout << ler << endl;
	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		if(i <= sms && i >= ler) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}

