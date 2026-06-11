#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,A,B;
	cin >> N >> A >> B;
	int ans = min(A*N, B);

	cout << ans << endl;
	return 0;
}
