#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define f(i, l, r) for (int i = l; i <= r; i++)
#define rf(i, r, l) for (int i = r; i >= l; i--)
#define all(x) (x).begin(), (x).end()
#define sf(a) scanf("%d",&a)
#define llsf(a) scanf("%lld", &a)
#define l l
#define r r
#define lch (o << 1)
#define rch (o << 1 | 1)
#define mid ((l + r) >> 1)
#define mem(x, y) memset(x, y, sizeof(x))

const int inf = 2e9 + 7;
const ll INF = INT64_MAX;
double eps = 1e-6;
int mod = 1e9 + 7;
const int N = 1e6 + 10;
const double pi = acos(-1.0);


int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	char s[5]; cin >> s;
	f(i, 0, 2)if (s[i] == '1') {
		s[i] = '9';
	}
	else s[i] = '1';
	cout << s;
}