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

int x[100010];
int diff[100010];

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main()
{
	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	x[N] = X;
	sort(x, x + N + 1);
	for (int i = 0; i < N; i++) {
		diff[i] = x[i + 1] - x[i];
	}
	int ans = diff[0];
	for (int i = 0; i < N; i++) {
		ans = gcd(ans, diff[i]);
		//cout << ans << endl;
	}
	cout << ans << endl;
}
