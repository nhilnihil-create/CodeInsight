#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i_length = (n); i < i_length; i++)
#define MOD 1000000007

int main() {
	vector<int> a(4);
	rep(i, 4) cin >> a[i];
	sort(a.begin(), a.end());
	if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}