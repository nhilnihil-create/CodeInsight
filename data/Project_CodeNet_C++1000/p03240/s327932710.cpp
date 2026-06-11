#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 120
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n;
map<int, vector<pii>> info;
int lis[maxn], cs = 0;

int dist(pii a, pii b){
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int main(){
	int x, y, z;
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d%d", &x, &y, &z);
		lis[++cs] = z;
		info[z].pb(pii(x, y));
	}
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	pii C; int H;
	rep(i, 0, 100) {
		rep(j, 0, 100) {
			pii now = pii(i, j);
			int nowh = -1;
			per(k, cs, 1){
				if (lis[k]) {
					int d = -1;
					for (auto it = info[lis[k]].begin(); it != info[lis[k]].end(); it++){
						if (d == -1) d = dist(*it, now);
						else if (d != dist(*it, now)) goto fail; 
					}
					if (nowh == -1) nowh = lis[k] + d;  
					else if (nowh != lis[k] + d) goto fail;
				}
				else {
					for (auto it = info[lis[k]].begin(); it != info[lis[k]].end(); it++){
						if (nowh > dist(*it, now)) goto fail; 
					}
				} 
			}
			if (nowh < 1) goto fail;
			C = now; H = nowh; goto done;
			fail:;
		}
	}
	done:; 
	printf("%d %d %d", C.fi, C.se, H);
	return 0;
}