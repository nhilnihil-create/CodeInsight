#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <functional>
#include <queue>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)

int X,Y,Z,K;

signed main()
{
	cin >> X >> Y >> Z >> K;

	vector<int> A(X), B(Y), C(Z);
	rep(i, X) cin >> A[i];
	rep(i, Y) cin >> B[i];
	rep(i, Z) cin >> C[i];

	vector<int> S;
	rep(i, X) rep(j, Y) S.push_back(A[i] + B[j]);

	sort(begin(S), end(S), greater<int>());
	sort(begin(C), end(C), greater<int>());

	vector<int> ans;

	int len = min(K, (int)S.size());
	rep(i, len) rep(j, Z) ans.push_back(S[i] + C[j]);

	sort(begin(ans), end(ans), greater<int>());

	rep(i, K) cout << ans[i] << endl;
}
