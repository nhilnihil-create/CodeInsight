#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int A, B, C;
	cin >> A >> B >> C;
	int p = min({A,B,C});
	int r = max({A,B,C});
	int q = A+B+C-p-r;

	if (p==q) {
		cout << r-q << endl;
		return 0;
	}
	if (q==r) {
		cout << (q-p+1)/2 + (q-p)%2 << endl;
		return 0;
	}

	int ans = (q-p+1)/2 + (q-p)%2;
	ans += r-q;
	cout << ans << endl;
	return 0;
}
