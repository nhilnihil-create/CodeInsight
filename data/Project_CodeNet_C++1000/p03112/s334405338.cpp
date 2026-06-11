#include <bits/stdc++.h>

using namespace std;

int n,m,q;
long long a[100005],b[100005];

long long get(long long x,int i,int j)
{
	if(i<0||j<0||i>=n||j>=m) return (1LL<<60);
	long long aa=a[i],bb=b[j];
	return min(llabs(x-aa)+llabs(aa-bb),llabs(x-bb)+llabs(aa-bb));
}

int main()
{
	cin >> n >> m >> q;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	sort(a,a+n); sort(b,b+m);
	while(q--)
	{
		long long x;
		cin >> x;
		int it1=lower_bound(a,a+n,x)-a;
		int it2=lower_bound(b,b+m,x)-b;
		long long ans=(1LL<<60);
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++)
				ans=min(ans,get(x,it1+i,it2+j));
		cout << ans << endl;
	}
}