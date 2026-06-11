#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef Hwang_Baek_I
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	cout << n - k + 1 << endl;	
	return 0;
}
