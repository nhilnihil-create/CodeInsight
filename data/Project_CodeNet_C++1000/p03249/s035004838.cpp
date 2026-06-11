#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define N 100100

ll n,cnt,dis;
ll d[N];
set<pair<ll,ll> > S;
ll sz[N],u[N],v[N];
set<pair<ll,ll> >::iterator it,it2;

int main()
{
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++) {
		scanf("%lld",&d[i]);
		S.insert(mp(d[i],i));
		sz[i]=1;
	}
	
	for (ll i=1;i<n;i++)
	{
		it=S.end(); it--;
		ll now=(*it).second,num=sz[now];
		S.erase(it);
		if (n-2*num<=0) return puts("-1"),0;
		it2=S.lower_bound(mp(d[now]-(n-2*num),0));
		if (it2==S.end() || (*it2).first!=d[now]-(n-2*num)) return puts("-1"),0;
		u[++cnt]=now; v[cnt]=(*it2).second;
		sz[(*it2).second]+=num;
		dis+=2*num*(n-num);
	}
	for (int i=1;i<=n;i++) dis-=d[i];
	if (dis!=0) return puts("-1"),0;
	for (ll i=1;i<=cnt;i++) printf("%lld %lld\n",u[i],v[i]);
	return 0;
}