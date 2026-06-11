#include<algorithm>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<deque>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M, X;
	int sum, ans = 0;
	int min = 1000;
	cin >> N >> X;
	sum = X;
	for (int i = 0; i < N; i++) {
		cin >> M;
		sum -= M;
		ans++;
		if (min > M)min = M;
	}
	while (1) {
		sum -= min;
		if (sum < 0)break;
		ans++;
	}
	cout << ans << endl;
}