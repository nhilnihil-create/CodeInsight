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

ll x[100010];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> x[i];
	ll ans = INF;
	for (int i = 0; i < N - K + 1; i++) {
		ans = min(ans, abs(x[i]) + x[i + K - 1] - x[i]);
		ans = min(ans, abs(x[i + K - 1]) + x[i + K - 1] - x[i]);
	}
	cout << ans << endl;
}