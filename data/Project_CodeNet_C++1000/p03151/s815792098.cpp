#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define EPS (1e-15)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define bet(x, a, b) (a) <= (x) && (x) < (b)
typedef long long ll;
typedef unsigned long long ull;

int A[100000];
int B[100000];

int main()
{
	int N, ans = 0;
	ll lack = 0;
	priority_queue<int> pq;

	cin >> N;
	rep(i, N) cin >> A[i];
	rep(i, N) cin >> B[i];

	rep(i, N) {
		if (A[i] < B[i]) {
			ans++;
			lack += B[i] - A[i];
		}
		else {
			pq.push(A[i] - B[i]);
		}
	}

	while (!pq.empty() && lack > 0) {
		lack -= pq.top(); pq.pop();
		ans++;
	}

	if (lack > 0) ans = -1;

	cout << ans << endl;

	return 0;
}
