#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long int				int32;
typedef unsigned long int		uint32;
typedef long long int			int64;
typedef unsigned long long int  uint64;
typedef pair<int, int>			PII;
typedef vector<int>				VI;
typedef vector<long long>		VLL;
typedef vector<string>			VS;
typedef vector<PII>				VII;
typedef vector<VI>				VVI;

#define MEM(a, b)				memset(a, (b), sizeof(a))
#define calctime				std::cout << setprecision(5) << fixed << "Time to completed program: " << (double)(clock() - start)/(CLOCKS_PER_SEC) << "s.\n";
#define FOR(i, j, k, in)		for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)		for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)		for (int i = (j); i >= (k); i -= (in))
#define RFORW(i, j, k, in)		for (int i = (j); i > (k); i -= (in))
#define aint64(cont)			cont.begin(), cont.end()
#define raint64(cont)			cont.end(), cont.begin()
#define sz(cont)				int((cont).size())
#define PB						push_back
#define MP						make_pair
#define EPS						1e-9
#define MOD						1000000007
#define PI						3.1415926535897932384626433832795
#define Ff						first
#define Ss						second
#define FastIO					ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define fileIO(name)			ifstream iFs(name".inp"); ofstream oFs(name".out");
#define fileio(name)			ifstream cin(name".inp"); ofstream cout(name".out");
#define endl					'\n'

//int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, -1, 0, 1, 1, -1, -1, 1};	

int a[1005][1005] = {};
int dp[1005][1005] = {};

int n, m;

int check(int i, int j) {
	return ((0 <= i) && (i < n) && (0 <= j) && (j < m));
}

int add(int64 a, int64 b, int mod) {
	return (a + b >= mod ? (a + b) % mod : a + b);
}

int main() {
	FastIO;
#ifndef ONLINE_JUDGE
	fileio("input");		//Remember to change this
#endif

	cin >> n >> m;

	FOR(i, 0, n, 1)FOR(j, 0, m, 1) {
		char c; cin >> c;
		a[i][j] = (c == '.' ? 0 : -1);
	}

	if (a[0][0] == -1) { cout << 0 << endl; return 0; }

	FOR(i, 1, n, 1) {
		if (a[i][0] == 0)
			a[i][0] = 1;
		else break;
	}
	FOR(j, 1, m, 1)
		if (a[0][j] == 0) a[0][j] = 1;
		else break;

	FOR(i, 1, n, 1) FOR(j, 1, m, 1) {
		if (a[i][j] == -1) continue;
		if (a[i - 1][j] > 0)
			a[i][j] = add(a[i][j], a[i - 1][j], 1e9 + 7);
		if (a[i][j - 1] > 0)
			a[i][j] = add(a[i][j], a[i][j - 1], 1e9 + 7);
	}

	cout << (a[n - 1][m - 1] > 0 ? a[n - 1][m - 1] : 0) << endl;


	//calctime
	return 0;
}