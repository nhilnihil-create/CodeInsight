// " --- IN THE NAME OF ALLAH --- " // ;)
// -------------------------------- // ;)

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

typedef pair <long long int, long long int> pii;
typedef long double ld;
typedef long long int lli;
#define recout(x) return cout << (x), 0
#define re(x) return(x)
#define _f first
#define _s second
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define stp(x) cout << setprecision(x) << fixed; 
const lli N = 1e6, N2 =  5e3 + 10, mod = 1e9 + 7, inf = 1e10;
const ld PI = 3.1415926535897932;
lli a[N], dp[N];
bool mark[N], vis[N];
//ld dou[N];
//vector <lli> v[N];
//queue <lli> q[N];
pii p[N];
//lli val[N];
//pair <ld, pii> p_3[N];
//string s[N];
//set <lli> s[N];
//char c[N];

int main() {
	fast;
	lli n, a, b;
	cin >> n >> a >> b;
	cout << min (a, b) << " ";
	lli c = a + b - n;
	if (c < 0)
		cout << 0;
	else
		cout << c;
}
