#include<cstdio>
#include<cstring>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
pair<int,int> l[MAXN],r[MAXN],id[MAXN];
bool used[MAXN];
int n;
ll ans=0;
bool cmp(pair<int,int> x,pair<int,int> y){
	return x>y;
}
ll goin(ll now,int x){
	if(now<id[x].first){
		ans+=id[x].first-now;
		now=id[x].first;
	}
	else if(now>id[x].second){
		ans+=now-id[x].second;
		now=id[x].second;	
	}
	return now;
}
int main(){
	SF("%d",&n);
	for(int i=1;i<=n;i++){
		SF("%d%d",&l[i].first,&r[i].first);	
		l[i].second=i;
		r[i].second=i;
		id[i].first=l[i].first;
		id[i].second=r[i].first;
	}
	sort(l+1,l+1+n,cmp);
	sort(r+1,r+1+n);
	bool flag=0;
	int cnta=1,cntb=1,las=0;
	for(int i=1;i<=n;i++){
		if(flag==0){
			while(used[l[cnta].second]==1)
				cnta++;
			used[l[cnta].second]=1;
			las=goin(las,l[cnta].second);
		}
		else{
			while(used[r[cntb].second]==1)
				cntb++;
			used[r[cntb].second]=1;
			las=goin(las,r[cntb].second);
		}
		flag^=1;
	}
	ll ans1=ans+abs(las);
	las=0;
	ans=0,cnta=1,cntb=1;
	flag=1;
	memset(used,0,sizeof used);
	for(int i=1;i<=n;i++){
		if(flag==0){
			while(used[l[cnta].second]==1)
				cnta++;
			used[l[cnta].second]=1;
			las=goin(las,l[cnta].second);
		}
		else{
			while(used[r[cntb].second]==1)
				cntb++;
			used[r[cntb].second]=1;
			las=goin(las,r[cntb].second);
		}
		flag^=1;
	}
	ll ans2=ans+abs(las);
	PF("%lld",max(ans1,ans2));
}