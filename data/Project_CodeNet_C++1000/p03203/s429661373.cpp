#include <bits/stdc++.h>
#define inc(l,i,r) for (int i=l;i<=r;i++)
#define dec(r,i,l) for (int i=r;i>=l;i--)
#define mid ((l+r)>>1)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define ___ putchar(10);
#define N 400400
using namespace std;
typedef long long ll;

int H, W, n, x[N], y[N];
vector<int> G[N];
set<pii > S;

int main() {//freopen("_in.txt","r",stdin);
	scanf("%d%d%d",&H,&W,&n);
	inc(1,i,n) scanf("%d%d",x+i,y+i), G[y[i]].push_back(x[i]), S.insert(mp(x[i],y[i]));
	inc(1,i,W) G[i].push_back(H+1), sort(G[i].begin(),G[i].end());
	
	int x = 1, y = 1, ans = H;
	while (x <= H && y <= W) {
		if (S.find(mp(x+1,y)) != S.end()) {
			ans = min(ans,x);
			break;
		}
		if (S.find(mp(x+1,y+1)) != S.end()) ++x;
		else {
			ans = min(ans,*lower_bound(G[y].begin(),G[y].end(),x) - 1);
			++x, ++y;	
		}
	}
	printf("%d\n",ans);
}