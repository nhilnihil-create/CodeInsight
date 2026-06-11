#include<bits/stdc++.h>
#define exi return puts("-1"),0
const int N=100005;
using namespace std;
typedef long long ll;
int n,no[N],sz[N],f[N],de[N];
pair<ll,int>d[N];
ll tp,ans;
map<ll,int>mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&d[i].first),
	d[i].second=i,sz[i]=1;
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)
	mp[d[i].first]=i;
	for(int i=n;i>1;i--){
		tp=d[i].first+2*sz[i]-n;
		//cerr<<d[i].first<<":"<<tp<<endl;
		if(sz[i]*2>=n||!mp[tp])exi;
		f[i]=mp[tp],sz[mp[tp]]+=sz[i];
	}
	//cerr<<"??\n";
	for(int i=2;i<=n;i++)
	de[i]=de[f[i]]+1,ans+=de[i];
	if(ans^d[1].first)exi;
	for(int i=2;i<=n;i++)
	printf("%d %d\n",d[i].second,d[f[i]].second);
}