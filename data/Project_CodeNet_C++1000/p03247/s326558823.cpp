#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

#define Rep(i,l,r) for (int i = (l); i <= (r); ++ i)
#define RepD(i,r,l) for (int i = (r); i >= (l); -- i)
#define RepG(i,x) for (int i = hd[x]; i; i = e[i].nxt)

const int N = 1005;

int n, st[N];
struct pt {int x, y;} a[N];

int jd (bool x) {return x? 1: -1;}

int main () {
	bool fl = 0;
	scanf ("%d%d%d", &n, &a[1].x, &a[1].y);
	if (!((a[1].x^a[1].y)&1)) fl = 1, ++ a[1].x;
	Rep(i,2,n) {
		scanf ("%d%d", &a[i].x, &a[i].y);
		if (fl) ++ a[i].x;
		if (!((a[i].x^a[i].y)&1)) {puts ("-1"); return 0;}
	}
	printf ("%d\n", 31+fl);
	if (fl) printf ("1 ");
	Rep(i,0,30) printf ("%d ", 1<<i);
	puts ("");
	Rep(k,1,n) {
		if (fl) putchar ('L');
		int x = a[k].x, y = a[k].y;
		RepD(i,30,0) {
			if (1ll*abs (x+(1<<i))+abs (y)<(1<<i)) x += (1<<i), st[i] = 1;
			else if (1ll*abs (x-(1<<i))+abs (y)<(1<<i)) x -= (1<<i), st[i] = 2;
			else if (1ll*abs (x)+abs (y+(1<<i))<(1<<i)) y += (1<<i), st[i] = 3;
			else y -= (1<<i), st[i] = 4;
		}
		Rep(i,0,30) {
			if (st[i]==1) putchar ('L');
			if (st[i]==2) putchar ('R');
			if (st[i]==3) putchar ('D');
			if (st[i]==4) putchar ('U');
		}
		puts ("");
	}
	return 0;
}
