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
	cin >> N;
	vector< pair<int, int> > I(N+1, {0, 0});
	for(int i = 0; i < N; i++) cin >> I[i].ff >> I[i].ss;
	vector<int> lft_ends(N+1), rt_ends(N+1);
	for(int i = 0; i < N+1; i++) {
		lft_ends[i] = I[i].ff;
		rt_ends[i] = I[i].ss;
	}
	sort(begin(lft_ends), end(lft_ends));
	sort(begin(rt_ends), end(rt_ends));
	cat ans = 0;
	for(int i = 0; i < (N+1)/2; i++) {
		if(lft_ends[N-i] <= rt_ends[i]) break;
		ans += 2 * (lft_ends[N-i] - rt_ends[i]);
	}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing
