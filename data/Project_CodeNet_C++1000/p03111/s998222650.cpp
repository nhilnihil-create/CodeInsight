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

int l[10];
int main()
{
	int N, A[3];
	cin >> N >> A[0] >> A[1] >> A[2];
	for (int i = 0; i < N; i++) cin >> l[i];
	int ans = mod;
	for (int bit = 0; bit < (1 << 2 * N); bit++) {
		int tmp = bit;
		int cnt = 0;
		int c[10] = { 0 };
		int sum[10] = { 0 };
		for (int i = 0; i < N; i++) {
			c[tmp % 4]++;
			sum[tmp % 4] += l[i];
			tmp /= 4;
		}
		for (int i = 0; i < 3; i++) {
			if (c[i] == 0) cnt = mod;
			cnt += 10 * (max(0,c[i] - 1));
			cnt += abs(sum[i] - A[i]);
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}
