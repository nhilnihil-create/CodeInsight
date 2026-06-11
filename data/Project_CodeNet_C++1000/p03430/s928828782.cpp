#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
int n, K;
char s[310];
int f[305][305][305];

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%d", &K);
	rep(k, 0, K)
		rrep(i, n, 1) {
			f[i][i][k] = 1;
			rep(j, i + 1, n) {
			f[i][j][k] = max(f[i + 1][j][k], f[i][j - 1][k]);
			if(s[i] == s[j]) f[i][j][k] = max(f[i][j][k], f[i + 1][j - 1][k] + 2);
			if(k) f[i][j][k] = max(f[i][j][k], f[i + 1][j - 1][k - 1] + 2);
			}
		}
	cout << f[1][n][K];
	return 0;
}
