#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N = 2e5 + 1000;
int n,top,a[N];
struct node{int pos,v;} sta[N];
void insert(int pos,int mid)
{
	while(sta[top].pos > pos) top --;
	if(sta[top].pos == pos) sta[top].v ++; else sta[++ top] = node{pos,1};
	if(top > 1 && sta[top].v == mid) top --,insert(pos - 1,mid);
}
int check(int mid)
{
	sta[top = 1] = node{0,0};
	for(int i = 2;i <= n;i ++) if(a[i - 1] >= a[i]) insert(a[i],mid);
	return sta[1].v == 0;
}
int main()
{
	n = read(); for(int i = 1;i <= n;i ++) a[i] = read();
	int cnt = 0; for(int i = 2;i <= n;i ++) cnt += a[i] > a[i - 1];
	if(cnt == n - 1) {puts("1"); return 0;}
	int l = 2,r = n,mid,ans = 1;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << "\n";
}