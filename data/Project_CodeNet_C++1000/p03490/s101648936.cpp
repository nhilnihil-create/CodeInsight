#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
using namespace std;
const int MAX = 1e5 + 10; //N
const ll MOD = 1e9 + 7;
int N, M, K, Q;

vector<int> mv[2];
int dest[2];
int dp[16010][4010];

int rec(int pos, int op, int dir, bool f) {
	if (op == mv[dir].size()) {
		if (pos == dest[dir]) return 1;
		else return 0;
	}
	int &ret = dp[pos][op];
	if (ret != -1) return ret;
	ret = 0;
	if (f) {
		ret = rec(pos + mv[dir][op], op + 1, dir, 0);
	}
	else {
		ret = rec(pos + mv[dir][op], op + 1, dir, 0);
		ret |= rec(pos - mv[dir][op], op + 1, dir, 0);
	}
	return ret;
}

int main()
{
	int i, j;
	string s;
	cin >> s;
	scanf("%d %d", &dest[0], &dest[1]);
	dest[0] += 8000;
	dest[1] += 8000;
	
	i = 0;
	int n = s.size();
	int dir = 0;
	bool f = false;
	if (s[0] == 'F') f = true;
	while (i < n) {
		int Fcnt = 0;
		int Tcnt = 0;
		while (i < n && s[i] == 'T') Tcnt++, i++;
		while (i < n && s[i] == 'F') Fcnt++, i++;
		if (Tcnt % 2 == 1) dir = !dir;
		if(Fcnt) mv[dir].push_back(Fcnt);
	}


	memset(dp, -1, sizeof(dp));
	int a = rec(8000, 0, 0, f);
	memset(dp, -1, sizeof(dp));
	int b = rec(8000, 0, 1, 0);
	if (a&&b) printf("Yes");
	else printf("No");
}