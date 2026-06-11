#include <iostream>
using namespace std;
long long ans[100005],fa[100005],sz[100005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
pair <int,int> a[100005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	long long qwq=0;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++)
		cin >> a[i].first >> a[i].second;
	for(int i=m;i>=1;i--)
	{
		ans[i]=(long long)n*(n-1)/2-qwq;
		if(ff(a[i].first)!=ff(a[i].second))
		{
			qwq+=sz[ff(a[i].first)]*sz[ff(a[i].second)];
			sz[ff(a[i].second)]+=sz[ff(a[i].first)];
			fa[ff(a[i].first)]=ff(a[i].second);
		}
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << "\n";
	return 0;
}