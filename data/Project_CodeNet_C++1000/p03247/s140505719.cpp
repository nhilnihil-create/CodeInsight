#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(pos, len) for(int pos=0;pos<len;pos++)
#define repp(pos, len) for(int pos=1;pos<=len;pos++)

#define INF 987654321
#define IINF 2987654321987654321
#define MOD 998244353

inline ll labs(ll n) { return (n > 0) ? n : -n; }

const int LOGX = 32;
ll p2[LOGX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dir[4] = {'L', 'D', 'R', 'U'};

void solve(ll x, ll y) {
	for(int t = LOGX-1; t >= 0; t--) {
		for(int k = 0; k < 4; k++) {
			if(labs(x - dx[k]*p2[t]) + labs(y - dy[k]*p2[t]) <= (p2[t]-1)) {
				printf("%c", dir[k]);
				x -= dx[k]*p2[t];
				y -= dy[k]*p2[t];
				break;
			}
		}
	}
	printf("\n");
}

int main() {
	for(int i = 0; i < LOGX; i++)
		p2[i] = (1LL<<i);

	int n; scanf("%d", &n);
	vector<pii> v(n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);

	bool flag = (v[0].first + v[0].second) & 1;
	for(int i = 0; i < n; i++) {
		if(flag ^ ((v[i].first + v[i].second) & 1)) {
			printf("-1\n");
			exit(0);
		}
	}

	if(!flag)
		for(int i = 0; i < n; i++)
			v[i].first--;

	printf("%d\n", flag ? LOGX : LOGX+1);
	if(!flag) printf("1 ");
	for(int i = LOGX-1; i >= 0; i--)
		printf("%lld ", p2[i]);
	printf("\n");

	for(int i = 0; i < n; i++) {
		if(!flag) printf("R");
		solve(v[i].first, v[i].second);
	}
}