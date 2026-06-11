#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define all(v)    ((v.begin()),(v.end()))
#define sz(v)     ((int)(v.size()))
#define forv(i, v) for(int i = 0; i < sz(v); ++i)
#define forn(i,n)   for(int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector< vi >    vii;
typedef vector< vd >    vdd;
typedef vector<string>  vs;
const int M = 305;

double dp[M][M][M];

int main()
{
	//fast;
	int n;
	scanf("%d", &n);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) cnt1++;

		if (x == 2) cnt2++;

		if (x == 3) cnt3++;
	}
	for (int c = 0; c <= n; c++) {
		for (int b = 0; b <= n; b++) {
			for (int a = 0; a <= n; a++) {

				int k = a + b + c;

				if (k == 0) continue;
				if (k > n) continue;

				dp[a][b][c] += (1.0 * n) / k;

				if (a)
					dp[a][b][c] += (1.0 * a) / k * dp[a - 1][b][c];
				if (b)
					dp[a][b][c] += (1.0 * b) / k * dp[a + 1][b - 1][c];
				if (c)
					dp[a][b][c] += (1.0 * c) / k * dp[a][b + 1][c - 1];

			}
		}
	}
	printf("%.12lf\n", dp[cnt1][cnt2][cnt3]);
	return 0;
}
