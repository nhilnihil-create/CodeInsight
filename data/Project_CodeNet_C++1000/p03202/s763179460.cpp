#include<cstdio>
#include<cstring>
using namespace std;
#define N 200010
int a[N];
struct {
	int x, s;
}st[N];
int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = 1, r = n, ans;
	while(l <= r) {
		int mid = (l + r) / 2;
		int s = 0, t = 0, ok = 1;
		for(i = 1; i <= n; i++) {
			if(a[i] > s) {
				st[++t].x = 1, st[t].s = a[i] - s;
				s = a[i];
			}
			else {
				int p = 0;
				while(s > a[i]) {
					if(s - st[t].s > a[i]) s -= st[t].s, st[t].s--, t--;
					else {
						st[t].s -= s - a[i];
						s = a[i];
					}
				}
				while(st[t].s == 0) t--;
				p = st[t].x;
				int j = t; 
				while(st[j].x == mid && j) j--;
				if(j == 0) {
					ok = 0;
					break;
				}
				if(st[j].s == 1) {
					j = t;
					while(st[j].x == mid && j) {
						st[j].x = 1;
						j--;
					}
					st[j].x++;
				}
				else {
					j = t, t++;
					while(st[j].x == mid && j) {
						st[j + 1] = st[j];
						st[j + 1].x  = 1;
						j--;
					}
					st[j + 1].x = st[j].x + 1, st[j + 1].s = 1;
					st[j].s--;
				}
				
			}
		}
		if(ok) ans = mid, r = mid - 1; else l = mid + 1;
	}
	printf("%d", ans);
	return 0;
}