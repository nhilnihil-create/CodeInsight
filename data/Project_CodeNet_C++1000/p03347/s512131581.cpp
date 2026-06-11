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

ll A[200010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll ans = 0;
	ll num = 0;
	A[N] = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > i) {
			cout << -1 << endl;
			return 0;
		}
		if (A[i] < A[i + 1] - 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] != 0) {
			if (A[i] == A[i + 1] - 1) {
				num = max(num, A[i]);
			}
			else {
				ans += num;
				num = A[i];
			}
		}
		else {
			ans += num;
			num = 0;
		}
	}
	cout << ans << endl;
}