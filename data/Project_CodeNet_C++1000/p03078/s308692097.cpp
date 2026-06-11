#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int X, Y, Z, K, A[1005], B[1005], C[1005];
priority_queue<pair<int, int> > pq;
 
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> X >> Y >> Z >> K;
	for (int i = 1; i <= X; i++) cin >> A[i];
	for (int i = 1; i <= Y; i++) cin >> B[i];
	for (int i = 1; i <= Z; i++) cin >> C[i];
	sort(C + 1, C + 1 + Z);
	for (int i = 1; i <= X; i++)
		for (int j = 1; j <= Y; j++)
			pq.emplace(A[i] + B[j] + C[Z], Z);
	while (K--) {
		auto ii = pq.top();
		pq.pop();
		cout << ii.first << '\n';
		if (ii.second > 1) pq.emplace(ii.first - C[ii.second] + C[ii.second - 1], ii.second - 1);
	}
}
