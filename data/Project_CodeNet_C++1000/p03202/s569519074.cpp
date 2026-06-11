#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], ans, top;
struct node{int v, c;}sta[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
void insert(int v, int x)
{
	while(sta[top].v > v) top --;
	if(sta[top].v == v) sta[top].c ++;
	else sta[++ top] = node{v, 1};
	if(top > 1 && sta[top].c == x) top --, insert(v - 1, x);
}
int check(int mid)
{
	sta[top = 1] = node{0, 0};
	for(int i = 2; i <= n; i ++) if(a[i] <= a[i - 1]) insert(a[i], mid);
	return sta[1].c == 0;
}
int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i ++) a[i] = read();
	int cnt = 0;
	for(int i = 2; i <= n; i ++) cnt += (a[i] > a[i - 1]);
	if(cnt == n - 1) {puts("1"); return 0;}
	int l = 2, r = n;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
