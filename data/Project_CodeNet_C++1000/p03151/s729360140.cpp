#include <cstdio>
#include <queue>
#define maxn 100005
using namespace std;

typedef long long LL;

LL a[maxn], b[maxn], sm, sp;
priority_queue<LL> q;

int main(int argc, char** argv)
{
	int n, res = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%lld", &a[i]);
	for(int i=0; i<n; i++) scanf("%lld", &b[i]);
	for(int i=0; i<n; i++)
		if(a[i] < b[i])
		{
			sm += b[i] - a[i];
			res ++;
		}
		else if(a[i] > b[i])
		{
			sp += a[i] - b[i];
			q.push(a[i] - b[i]);
		}
	if(sm > sp) {puts("-1"); return 0;}
	if(sm == 0) {puts("0"); return 0;}
	while(!q.empty())
	{
		LL x = q.top(); q.pop();
		sm -= x, res ++;
		if(sm <= 0)
		{
			printf("%d\n", res);
			return 0;
		}
	}
	return 0;
}