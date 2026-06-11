#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9')	{if(ch == '-')	f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N = 2e5 + 5;
int n , top;
int a[N];
struct node
{
	int v , c;
	node(int v = 0,int c = 0) : v(v) , c(c) {}
} st[N];
void insert(int v,int x)
{
	while(st[top].v > v) top --;
	if(st[top].v == v) st[top].c ++;
	else st[++ top] = node(v,1);
	if(top > 1 && st[top].c == x) top -- , insert(v - 1,x);
}
inline bool check(int mid)
{
	st[top = 1] = node();
	for(int i = 2;i <= n;i ++) if(a[i] <= a[i - 1]) insert(a[i],mid);
	return st[1].c == 0;
}
int main()
{
	n = read(); a[1] = read(); int cnt = 0;
	for(int i = 2;i <= n;i ++) a[i] = read() , cnt += a[i] <= a[i - 1];
	if(!cnt) return puts("1") , 0;
	int l = 2 , r = n , ans = 0;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid , r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n",ans);
	return 0;
}