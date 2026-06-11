#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int A, B;
	cin >> A >> B;
	int ans;
	if (A >= 13) ans = B;
	if (A >= 6 && A <= 12) ans = B/2;
	if (A <= 5) ans = 0;
	cout << ans << endl;
	return 0;
}
