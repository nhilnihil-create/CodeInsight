#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define lowbit(x) x&(-x)
#define PII  pair<int, int> 
#define all(x) x.begin(), x.end()
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;
const ll inf = 1e18;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e3 + 5;
using namespace std;

#define int ll

struct node{
	int x, y;
}a[maxn];

int d[50];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
string s = "LRUD";
int n, cnt = 0;

int dis(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

void work(int x, int y){
	node now;
	now.x = now.y = 0;
	for(int i = 1; i <= cnt; i++){
		int Min = inf;
		int pos = 0;
		for(int j = 0; j < 4; j++){
			int tx = now.x + dir[j][0] * d[i], ty = now.y + dir[j][1] * d[i];
			int t = dis(tx, ty, x, y);
			if(Min > t) Min = t, pos = j;
		}
		now.x += d[i] * dir[pos][0], now.y += d[i] * dir[pos][1];
		putchar(s[pos]);
	}
	puts("");
}

int32_t main()
{
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld %lld", &a[i].x, &a[i].y);
		if((abs(a[i].x + a[i].y) & 1) != (abs(a[1].x + a[1].y) & 1)) return 0 * puts("-1");
	}
	for(int i = 30; i >= 0; i--){
		d[++cnt] = 1 << i;
	}
	if((a[1].x + a[1].y) % 2 == 0) d[++cnt] = 1;
	printf("%lld\n", cnt);
	for(int i = 1; i < cnt; i++)
		printf("%lld ", d[i]);
	printf("%lld\n", d[cnt]);
	for(int i = 1; i <= n; i++){
		work(a[i].x, a[i].y);
	}
	return 0;
}