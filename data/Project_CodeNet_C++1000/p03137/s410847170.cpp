#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;
const int MOD = 998244353;

int X[100010];
int diff[100010];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> X[i];
	sort(X, X + M);
	if (N >= M) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = X[M - 1] - X[0];
	for (int i = 0; i < M - 1; i++) {
		diff[i] = X[i + 1] - X[i];
	}
	sort(diff, diff + M - 1, greater<int>());
	for (int i = 0; i < N - 1; i++) {
		ans -= diff[i];
	}
	cout << ans << endl;
}
