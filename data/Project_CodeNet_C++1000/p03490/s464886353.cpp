#include<bits/stdc++.h>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

template <typename tn> void read (tn & a) {
	tn x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9'){ if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9'){ x = x * 10 + c - '0'; c = getchar(); }
	a = f == 1 ? x : -x;
}

const int MAXN = 8100;
int n;
ll fx[MAXN], fy[MAXN], sx, sy;
ll dp[2][MAXN + MAXN];
int s[MAXN];
int x, y, tfx, tfy;

void init() {
//	cerr<<"??\n";
	char c = getchar();
//	cerr<<"  c = "<<c<<"\n";
	while (c != 'F' && c != 'T') {
		c = getchar();
//	cerr<<"  c = "<<c<<"\n";
	}
	n = 0;
//	cerr<<"??\n";
	while (c == 'F' || c == 'T') {
		s[++n] = c == 'F' ? 1 : 0;
		c = getchar();
	}
	read(x); read(y);
}

int main() {
//	freopen("in.txt","r",stdin);
	
//	read(n);
//	cerr<<"n = "<<n<<"\n";
//	freopen("out.txt","w",stdout);
////	string str;
//	scanf("%s",str);
//	n=strlen(str);
//	cerr<<" n = "<<n<<"\n";

//	string s;
//	cin >> s;
//	cerr<<s<<"\n";
//	cin >> s;
//	cerr<<s<<"\n";

	init();
	int tf = 1; sx = sy = 0;
	rep(i, 0, n) {
		int j = i;
		while (j < n && s[j + 1]) ++j;
		int l = j - i;
		if (tf) { fx[++sx] = l; if (l != 0) tfx = 1; }
		else { fy[++sy] = l; if (l != 0) tfy = 1; }
		tf = 1 - tf; i = j;
	}
	dp[1][fx[1] + MAXN] = 1;
	rep(i, 2, sx) {
		int k = i % 2;
		rep(j, 0, MAXN + MAXN - 1) dp[k][j] = 0;
		rep(j, 0, MAXN + MAXN - 1) {
			if (j - fx[i] >= 0) dp[k][j] |= dp[1 - k][j - fx[i]];
			if (j + fx[i] < MAXN + MAXN) dp[k][j] |= dp[1 - k][j + fx[i]];
		}
	}
	bool tx = dp[sx % 2][x + MAXN] || (tfx == 0 && x == 0) ? 1 : 0;
	rep(j, 0, MAXN + MAXN - 1) dp[1][j] = 0;
	dp[1][MAXN-fy[1]] = 1; dp[1][fy[1] + MAXN] = 1;
	rep(i, 2, sy) {
		int k = i % 2;
		rep(j, 0, MAXN + MAXN - 1) dp[k][j] = 0;
		rep(j, 0, MAXN + MAXN - 1) {
			if (j - fy[i] >= 0) dp[k][j] |= dp[1 - k][j - fy[i]];
			if (j + fy[i] < MAXN + MAXN) dp[k][j] |= dp[1 - k][j + fy[i]];
		}
	}
	bool ty = dp[sy % 2][y + MAXN] || (tfy == 0 && y == 0) ? 1 : 0;
	if (tx && ty) printf("Yes\n"); else printf("No\n");
	return 0;
}
