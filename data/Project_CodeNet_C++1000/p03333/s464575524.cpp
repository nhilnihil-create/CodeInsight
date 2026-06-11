#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
typedef pair<int,int>pii;
priority_queue<pii>q1,q2;
int n,l[N],r[N],i,x,y,dt;
bool b[N];
ll ans;
inline ll calc(){
	ll ans=y=0;
	for(i=1;i<=n;++i)q1.push(pii(l[i],i)),q2.push(pii(-r[i],i));
	memset(b+1,0,n);
	for(i=1;i<=n;++i){
		for(;b[q1.top().second];q1.pop());
		for(;b[q2.top().second];q2.pop());
		if(i&1)x=q1.top().second,ans+=dt=max(0,q1.top().first-y),y+=dt,q1.pop();
			else x=q2.top().second,ans+=dt=max(0,y+q2.top().first),y-=dt,q2.pop();
		b[x]=1;
	}
	for(;!q1.empty();q1.pop());for(;!q2.empty();q2.pop());
	return ans+abs(y);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",l+i,r+i);
	ans=calc();for(i=1;i<=n;++i)swap(l[i],r[i]),l[i]*=-1,r[i]*=-1;
	ans=max(ans,calc());printf("%lld\n",ans);
}