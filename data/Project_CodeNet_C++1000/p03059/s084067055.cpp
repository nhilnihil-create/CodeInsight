#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int A, B, T;
	cin >> A >> B >> T;
	int ans = 0;
	for (int i = 1; i <= T; i++){
		if (i%A == 0) ans += B;
	}
	cout << ans << endl;
	return 0;
}
