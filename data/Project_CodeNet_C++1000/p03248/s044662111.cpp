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

bool flag = 1;
char s[N];
vector<int> g[N];
int tot,w,len;
void connect(int fa,int now,int num) {
	if (num <= 1)return;

	if (w % 2 == 0 && w / 2 == num) {
		f(i, 1, num - 1)g[now].push_back(++tot);
	}
	else if (num >= w / 2 + 1) {
		bool yy = 1;
		if (w % 2) {
			rf(i, num - 1, w / 2 + 1)if (s[i] == '1') {
				int tmp = w - tot - i;
				f(i, 1, tmp) {
					g[now].push_back(++tot);
				}
				g[now].push_back(++tot);
				connect(now, tot, i); yy = 0;
				break;
			}
		}
		else {
			rf(i, num - 1, w / 2 )if (s[i] == '1') {
				int tmp = w - tot - i;
				f(i, 1, tmp) {
					g[now].push_back(++tot);
				}
				g[now].push_back(++tot);
				connect(now, tot, i); yy = 0;
				break;
			}
		}
		if (yy) {
			while (tot < w)g[now].push_back(++tot);
		}
	}
}
int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	scanf("%s", s+1);
	w = strlen(s + 1); flag = 1;
	if (s[w] == '1')flag = 0;
	f(i, 1, w)if (s[i] == '1') {
		if (s[w - i] != '1') {
			flag = 0;
		}
	}
	f(i, 1, w / 2)if (s[i] == '1')len++; else break;
	if (len == 0)flag = 0;
	else {
		tot = len + 1;
		f(i, 1, len)g[i].push_back(i + 1);
		connect(len,len+1, w - len);
	}

	if (flag) {
		f(i, 1, w)if (g[i].size()) {
			for (auto it : g[i])
				cout << i << " " << it << '\n';
		}
	}
	else cout << -1;
}