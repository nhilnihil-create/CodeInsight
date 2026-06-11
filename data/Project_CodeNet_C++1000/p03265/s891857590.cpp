#include <bits/stdc++.h>
//#include "stdc++.h"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = max(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int dy = y2 - y1;
	int dx = x2 - x1;
	
	printf("%d %d %d %d\n", x2 - dy, y2 + dx, x1 - dy, y1 + dx);
}
