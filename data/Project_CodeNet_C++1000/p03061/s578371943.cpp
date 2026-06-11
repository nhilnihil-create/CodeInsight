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

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	return gcd(y, x % y);
}
int A[100010];
int L[100010], R[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	L[0] = A[0];
	R[N - 1] = A[N - 1];
	for (int i = 1; i < N; i++) {
		L[i] = gcd(L[i - 1], A[i]);
		R[N - i - 1] = gcd(R[N - i], A[N - i - 1]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) ans = max(ans, R[i + 1]);
		else if (i == N - 1) ans = max(ans, L[i - 1]);
		else  ans = max(ans, gcd(L[i - 1], R[i + 1]));
	}
	cout << ans << endl;
}