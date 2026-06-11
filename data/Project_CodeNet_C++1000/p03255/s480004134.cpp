#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat X;
	cin >> N >> X;
	vector<cat> pos(N);
	for(int i = 0; i < N; i++) cin >> pos[i];
	vector<cat> S(N+1, 0);
	for(int i = 0; i < N; i++) S[i+1] = S[i] + pos[i];
	cat ans = 2LL * X * N + 10LL * S[N];
	for(int k = 1; k <= N; k++) {
		int cnt = 0;
		cat cur = (k + N) * X;
		for(int i = N-1; i >= 0; i -= k) {
			cat mul = (cnt == 0) ? 5 : (2 * cnt + 3);
			cur += (S[i+1] - S[max(0, i-k+1)]) * mul;
			cnt++;
			if(cur > ans) break;
		}
		ans = min(ans, cur);
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
