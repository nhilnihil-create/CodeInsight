#include <bits/stdc++.h>
using namespace std;
struct Data{
	int x,idx;
	bool operator<(const Data&r)const{
		return x<r.x;
	}
}l[100010],r[100010];
int chk[100010],b[100010];
int main(){
	int i,j,n;
	long long s,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&l[i].x,&r[i].x),l[i].idx=i,r[i].idx=i;
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	s=abs(r[1].x);
	chk[r[1].idx]=1;
	for(i=1,j=n;;){
		for(;j&&chk[l[j].idx];--j);
		if(!j||r[i].x>l[j].x){
			ans=max(ans,s+abs(r[i].x));
			break;
		}
		s+=abs(l[j].x-r[i].x);
		chk[l[j].idx]=1;
		for(;i<=n&&chk[r[i].idx];++i);
		if(i>n||r[i].x>l[j].x){
			ans=max(ans,s+abs(l[j].x));
			break;
		}
		s+=abs(r[i].x-l[j].x);
		chk[r[i].idx]=1;
	}
	for(i=1;i<=n;++i)chk[i]=0;
	s=abs(l[n].x);
	chk[l[n].idx]=1;
	for(i=1,j=n;;){
		for(;i<=n&&chk[r[i].idx];++i);
		if(i>n||r[i].x>l[j].x){
			ans=max(ans,s+abs(l[j].x));
			break;
		}
		s+=abs(r[i].x-l[j].x);
		chk[r[i].idx]=1;
		for(;j&&chk[l[j].idx];--j);
		if(!j||r[i].x>l[j].x){
			ans=max(ans,s+abs(r[i].x));
			break;
		}
		s+=abs(l[j].x-r[i].x);
		chk[l[j].idx]=1;
	}
	printf("%lld",ans);
	return 0;
}
