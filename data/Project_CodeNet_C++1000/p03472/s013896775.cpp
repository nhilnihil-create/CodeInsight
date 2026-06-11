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

int a[100010], b[100010];
int main()
{
	int N, H;
	cin >> N >> H;
	int k = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
		k = max(k, a[i]);
	}
	sort(b, b + N, greater<int>());
	int ans = 0;
	int i = 0;
	while (H > 0) {
		if (b[i] > k) H -= b[i];
		else {
			ans += (H + k - 1) / k;
			break;
		}
		ans++;
		i++;
	}
	cout << ans << endl;
}