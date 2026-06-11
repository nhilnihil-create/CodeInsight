#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN	110

int N;
struct P {
    int x, y, h;
};
P ps[MAXN];

int h[MAXN][MAXN];

inline int calcH(int cx, int cy, int ch, int x, int y) {
	return max(ch-abs(x-cx)-abs(y-cy), 0);
}

int isok(int cx, int cy, int ch) {
    for(int i=0; i<N; i++) {
        if(calcH(cx, cy, ch, ps[i].x, ps[i].y) != ps[i].h) {
            return 0;
        }
    }
    return 1;
}
int main() {
  scanf("%d", &N);
  int a, b, c;
  int mx, my, t;
  mx = my = 0;
  for(int i=0; i<N; i++) {
    scanf("%d%d%d", &a, &b, &c);
    mx = max(mx, a);
    my = max(my, b);
    if(c) t = i;
    ps[i].x = a; ps[i].y= b; ps[i].h = c;
  }
    for(int x=0; x<=mx; x++) {
        for(int y=0; y<=my; y++) {
            int h = ps[t].h + abs(ps[t].x-x)+abs(ps[t].y-y);
            if(isok(x, y, h)) {
                printf("%d %d %d\n", x, y, h);
                exit(0);
            }
        }
  }
  return 0;
}