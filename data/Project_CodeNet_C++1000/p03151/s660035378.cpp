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

vector<int> E;
int A[100010], B[100010];
int main()
{
	int N;
	cin >> N;
	ll sum1 = 0, sum2 = 0;
	ll sum = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int i = 0; i < N; i++) {
		sum1 += A[i];
		sum2 += B[i];
		if (A[i] < B[i]) {
			sum += B[i] - A[i];
			ans++;
		}
		else E.push_back(A[i] - B[i]);
	}
	if (sum1 < sum2) {
		cout << -1 << endl;
		return 0;
	}
	sort(E.rbegin(), E.rend());
	int i = 0;
	while (sum > 0) {
		sum -= E[i++];
		ans++;
	}
	cout << ans << endl;
}
