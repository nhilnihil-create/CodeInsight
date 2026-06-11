#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a[5];
	FOR(i,0,5)
	{
		cin >> a[i];
	}
	sort(a, a + 5);
	int best = 1000000;
	do {

		int t = 0;
		FOR(i,0,5)
		{
			t += a[i];
			if (i < 4)
				while (t % 10 != 0) {
					t++;
				}
		}
		best = min(best, t);

	} while (next_permutation(a, a + 5));

	cout << best << "\n";

}
