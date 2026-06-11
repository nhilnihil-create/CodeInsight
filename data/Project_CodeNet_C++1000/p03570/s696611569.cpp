#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = (1 << 26) + 10;
string s;
int n, ans, a[N];
int main()
{
	cin >> s;
	n = s.size();
	s = " " + s;
	int now = 0;
	a[0] = 1;
	ans = 2e9;
	rep(i, 1, n)
	{
		now = now ^ (1 << (s[i] - 'a'));
		int tmp = 2e9;
		if(a[now]) tmp = a[now];
		rep(j, 0, 25)
		{
			int ret = now ^ (1 << j);
			if(a[ret]) tmp = min(tmp, a[ret]);
		}
		if(i == n) ans = tmp + 1;
		if(!a[now]) a[now] = tmp + 1;
		else a[now] = min(a[now], tmp + 1);
	}
	cout << ans - 1;
	return 0;
}