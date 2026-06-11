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

ll V[60];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> V[i];
	ll ans = 0;
	for (int l = 0; l <= min(N, K); l++) {
		ll sum = 0;
		priority_queue<ll> que;
		priority_queue<ll> t;
		for (int i = 0; i < l; i++) {
			sum += V[i];
			if (V[i] < 0) que.push(-V[i]);
		}
		t = que;
		ll tmp = sum;
		for (int r = 0; r <= min(N - l, K - l); r++) {
			sum = tmp;
			que = t;
			for (int j = 0; j < r; j++) {
				sum += V[N - 1 - j];
				if (V[N - 1 - j] < 0) que.push(-V[N - 1 - j]);
			}
			int cnt = K - l - r;
			for (int c = 0; c < cnt && !que.empty(); c++) {
				int num = que.top();
				que.pop();
				num *= -1;
				sum -= num;
			}
			//if (l == 2 && r == 1) cout << sum << endl;
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}
