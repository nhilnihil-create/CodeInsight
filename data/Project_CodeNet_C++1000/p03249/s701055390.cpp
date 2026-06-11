#include<bits/stdc++.h>
#define MN 100000
#define ll long long
#define mp(x,y) make_pair(x,y)
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,ansnum,g[MN+5];ll f[MN+5];
pair<int,int> ans[MN+5];
set<pair<ll,pair<int,int> >,greater<pair<ll,pair<int,int> > > >st;
set<pair<ll,pair<int,int> > >::iterator it;
int main()
{
    n=read();
    for(int i=1;i<=n;++i) st.insert(mp(read(),mp(i,g[i]=1)));
    while(st.size()>1)
    {
        pair<ll,pair<int,int> >a=*st.begin(),b;
        st.erase(st.begin());
        ll nx=a.first+a.second.second-(n-a.second.second);
        it=st.lower_bound(mp(nx,mp(1e9,1e9)));
        if(it==st.end()||(*it).first!=nx) return 0*puts("-1");
        b=*it;st.erase(it);
        ans[++ansnum]=mp(a.second.first,b.second.first);
        b.second.second+=a.second.second;
        st.insert(b);
    }
    for(int i=1;i<n;++i) f[ans[i].second]+=f[ans[i].first]+g[ans[i].first],g[ans[i].second]+=g[ans[i].first];
    if(f[st.begin()->second.first]!=st.begin()->first) return 0*puts("-1");
    for(int i=1;i<n;++i) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
