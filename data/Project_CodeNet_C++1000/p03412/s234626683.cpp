#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define dom 998244353
#define all(c) begin(c),end(c)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
#define long long long
#define List vector
#define var auto
#define Count size()
#define Length size()
int dd[] = { 0, 1, 0, -1, 0 }; //→↓←↑

void solve()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	
	int ans = 0;
	for (int r = 28; r >= 0; r--)
	{
		int T = 1 << r;
		for (int i = 0; i < N; i++)
		{
			A[i] &= ~(T << 1);
			B[i] &= ~(T << 1);
		}
		sort(all(B));

		long x = 0;
		for(var v : A)
		{
			x += (int)(lower_bound(all(B), 2 * T - v) - lower_bound(all(B), T - v))
				+ (int)(lower_bound(all(B), 4 * T - v) - lower_bound(all(B), 3 * T - v));
		}
		if ((x & 1) == 1)
		{
			ans += T;
		}
	}
	cout << ans << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
