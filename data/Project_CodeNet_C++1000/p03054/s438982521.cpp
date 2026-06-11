#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))
#define inf 2147483647
#define int long long

signed main()
{
	int h, w, n, sr, sc, m[4];
	string s, t;

	cin >> h >> w >> n;
	cin >> sr >> sc;
	cin >> s;
	cin >> t;

	m[0] = 1;
	m[1] = w;
	m[2] = 1;
	m[3] = h;

	deps (i, n - 2, 1)
	{
		if (s[i] == 'L') m[0]++;
		else if (s[i] == 'R') m[1]--;
		else if (s[i] == 'U') m[2]++;
		else m[3]--;

//		if (sc < m[0] || m[1] < sc || sr < m[2] || m[3] < sr)  {cout << "NO" << endl; return 0;}
		if (m[0] == m[1] || m[2] == m[3])  {cout << "NO" << endl; return 0;}

		if (t[i - 1] == 'L') m[1] = min(m[1] + 1, w);
		else if (t[i - 1] == 'R') m[0] = max(m[0] - 1, 1);
		else if (t[i - 1] == 'U') m[3] = min(m[3] + 1, h);
		else m[2] = max(m[2] - 1, 1);
	}
	if (s[0] == 'L') m[0]++;
	else if (s[0] == 'R') m[1]--;
	else if (s[0] == 'U') m[2]++;
	else m[3]--;
	if (sc < m[0] || m[1] < sc || sr < m[2] || m[3] < sr)  {cout << "NO" << endl; return 0;}
	cout << "YES" << endl;
}
