# include <iostream>
# include <cstdio>
using namespace std;
const int N = 1e5 + 12;
long long C,ans;
long long x[N << 1],v[N << 1],g[N << 1];
int n,que[N << 1],t,h;
int id(int i){return i <= n ? i : i - n;}
long long f(int i){return g[i] - x[i + 1] + min(x[id(i + 1)],C - x[id(i + 1)]);}
int main()
{
	scanf("%d %lld",&n,&C);
	for(int i = 1;i <= n;i++)scanf("%lld %lld",&x[i],&v[i]),x[n + i] = x[i] + C,v[n + i] = v[i];
	for(int i = 1;i < n * 2;i++)g[i] = g[i - 1] + v[i];
	h = t = 0;
	for(int i = 1;i < n * 2;i++)
	{
		while(h < t && i - que[h] > n)h++;
		ans = max(ans,g[i] - x[i] - f(que[h]));
		while(h < t && f(i) <= f(que[t]))t--;
		que[++t] = i;
	}
	for(int i = 1;i <= n;i++)x[i] = C - x[i];
	for(int a = 1,b = n;a < b;a++,b--)swap(x[a],x[b]),swap(v[a],v[b]);
	for(int i = 1;i <= n;i++)x[n + i] = x[i] + C,v[n + i] = v[i];
	for(int i = 1;i < n * 2;i++)g[i] = g[i - 1] + v[i];
	h = t = 0;
	for(int i = 1;i < n * 2;i++)
	{
		while(h < t && i - que[h] > n)h++;
		ans = max(ans,g[i] - x[i] - f(que[h]));
		while(h < t && f(i) <= f(que[t]))t--;
		que[++t] = i;
	}
	printf("%lld\n",ans);
	
}