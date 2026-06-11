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

ll A[100010];
int main()
{
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) cin >> A[i];
	if (A[K - 1] != 2) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = 2;
	// 最小
	for (int i = K - 1; i >= 0; i--) {
		ans = (ans + A[i] - 1) / A[i] * A[i];
	}
	ll num = ans;
	for (int i = 0; i < K; i++) {
		num = num - (num % A[i]);
	}
	if (num == 2)cout << ans << " ";
	else {
		cout << -1 << endl;
		return 0;
	}
	//cout << endl;

	ans = 2;
	//最大
	for (int i = K - 1; i >= 0; i--) {
		ans = ans / A[i] * A[i] + A[i] - 1;
	}
	cout << ans << endl;
}