#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
int main()
{
	int n,i,x,y;
	scanf("%i",&n);
	vector<int> l,r,lm,rm;
	vector<pair<int,int> > m;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&x,&y);
		l.pb(y);
		r.pb(x);
	}
	l.pb(0);
	r.pb(0);
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	reverse(r.begin(),r.end());
	ll ans=0;
	for(i=0;i<n;i++)
	{
		if(l[i]<r[i]) ans+=-l[i]*2+r[i]*2;
	}
	printf("%lld\n",ans);
	return 0;
}