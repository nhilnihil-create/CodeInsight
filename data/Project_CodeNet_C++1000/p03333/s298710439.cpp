/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++) 
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,a[100010],b[100010],ans=0,now=0;
multiset <pii> sa,sb,svsa,svsb;//sa:左节点最大;sb:右节点最小 

LL solve(int whi)
{
	now=0;
	LL ret=0;
	pii to;
	int fw=whi;
	while(sa.size()>0)
	{
		if(whi==0)
		{
			to=*sa.begin();
			//if(fw==0)cout<<to.fi<<' '<<to.se<<' '<<now<<endl;
			if(-to.fi<=now&&now<=-to.se) break;
			sa.erase(sa.begin());
			sb.erase(sb.find({-to.se,-to.fi}));
		}
		else
		{
			to=*sb.begin();
			if(to.se<=now&&now<=to.fi) break;
			sb.erase(sb.begin());
			sa.erase(sa.find({-to.se,-to.fi}));
		}
		if(whi==0)
		{
			to.fi=-to.fi;
			to.se=-to.se;
		}
		if(abs(now-to.fi)<abs(now-to.se))
		{
			ret+=abs(now-to.fi);
			now=to.fi;
		}
		else
		{
			ret+=abs(now-to.se);
			now=to.se;
		}
		//if(fw==0) cout<<now<<' '<<ret<<' '<<whi<<' '<<to.fi<<' '<<to.se<<endl;
		whi^=1;
	}
	return ret+abs(now);
}

int main()
{
	cin>>n;
	rep(i,n)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		sa.insert({-a[i],-b[i]});
		sb.insert({b[i],a[i]});
	}
	svsa=sa;
	svsb=sb;
	ans=solve(0);//先取sa中的 
	sa=svsa;
	sb=svsb;
	ans=max(ans,solve(1));//先取sb中的 
	cout<<ans<<endl;
	rt0;
}