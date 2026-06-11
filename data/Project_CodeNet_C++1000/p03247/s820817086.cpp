#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;

int n, cnt = 0;
ll ans[50];
struct anode{
  ll x, y;
  anode() {}
  anode(ll _x, ll _y):x(_x), y(_y) {}
}a[maxn];
char f[maxn][50];

inline void work(ll k) {
  cnt ++; ans[cnt] = k;
  for(int i = 1;i <= n;i ++) {
    if(abs(a[i].x) > abs(a[i].y)) {
      if(a[i].x > 0) a[i].x -= k, f[i][cnt] = 'R';
      else a[i].x += k, f[i][cnt] = 'L';
		}
		else {
		  if(a[i].y > 0) a[i].y -= k, f[i][cnt] = 'U';
		  else a[i].y += k, f[i][cnt] = 'D';
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++) scanf("%lld%lld", &a[i].x, &a[i].y);
	for(int i = 30;i >= 0;i --)
	  work(1LL << i);
	if(a[1].x || a[1].y) work(1);
	for(int i = 1;i <= n;i ++) {
	  if(a[i].x || a[i].y) {
	    puts("-1");
	    return 0;
		}
	}
	printf("%d\n", cnt);
	for(int i = 1;i <= cnt;i ++) printf("%d ", ans[i]);
	for(int i = 1;i <= n;i ++) {
	  for(int j = 1;j <= cnt;j ++) printf("%c", f[i][j]);
	  puts("");
	}
  return 0;
}