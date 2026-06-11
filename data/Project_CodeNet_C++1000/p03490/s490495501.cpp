#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n),reverse(a,a+n)
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%s", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int xx[8000];
int yy[8000];

int main() {
//	PLAY();

	string s;
	cin >> s;
	int  x, y, j, c, xm = 0, ym = 0;

	cin >> x >> y;

	c = 0; j = 0;
	for (int i = 0; i <= sz(s); i++){
		if (s[i] == 'F')
			c++;
		else {
			if (j % 2) yy[j] = c;
			else xx[j] = c;
			c = 0;
			j++;
		}
	}
	xm = xx[0];
	xx[0] = 0;
	sortad(xx, sz(s));
	sortad(yy, sz(s));
	for (int i = 0; xx[i] != 0; i++) {
		if (xm <= x)
			xm += xx[i];
		else
			xm -= xx[i];
	}
	for (int i = 0; yy[i] != 0; i++) {
		if (ym <= y)
			ym += yy[i];
		else
			ym -= yy[i];
	}

	printf("%s\n", xm == x&&ym == y ? "Yes" : "No");

	return 0;
}