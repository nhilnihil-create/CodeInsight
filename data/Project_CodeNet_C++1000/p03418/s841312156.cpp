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

int main()
{
	int N, K;
	cin >> N >> K;
	ll ans = 0;
	for (int i = K + 1; i <= N; i++) {
		ans += max(0, (N % i) + 1 - K);
		ans += (N / i) * (i - K);
	}
	if (K == 0) ans = (ll)N * N;
	cout << ans << endl;
}