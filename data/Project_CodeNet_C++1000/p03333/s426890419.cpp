#include <stdio.h>
#include <algorithm>
#define MN 100000
struct SEG{int l,r;bool u;}s[MN+5];
int n,now;
long long ans1=0,ans2=0;
int l[MN+5],r[MN+5];
bool cmp1(int a,int b){return s[a].r<s[b].r;}
bool cmp2(int a,int b){return s[a].l>s[b].l;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i].l,&s[i].r);
		l[i]=i,r[i]=i;
	}
	std::sort(l+1,l+1+n,cmp1);
	std::sort(r+1,r+1+n,cmp2);
	#define ans ans1
	now=0;
	for(int i=1;i<=n;i++)
		s[i].u=false;
	for(int i=1,j=1;i<=n&&j<=n;){
		while(s[l[i]].u&&i<=n)i++;
		if(i>n)break;
		if(!(s[l[i]].l<=now&&s[l[i]].r>=now)){
			ans+=std::abs(now-s[l[i]].r);
			now=s[l[i]].r;
		}
		s[l[i]].u=true;
		while(s[r[j]].u&&j<=n)j++;
		if(j>n)break;
		if(!(s[r[j]].l<=now&&s[r[j]].r>=now)){
			ans+=std::abs(now-s[r[j]].l);
			now=s[r[j]].l;
		}
		s[r[j]].u=true;
	}
	ans+=std::abs(now);
	#undef ans
	#define ans ans2
	now=0;
	for(int i=1;i<=n;i++)
		s[i].u=false;
	for(int i=1,j=1;i<=n&&j<=n;){
		while(s[r[j]].u&&j<=n)j++;
		if(j>n)break;
		if(!(s[r[j]].l<=now&&s[r[j]].r>=now)){
			ans+=std::abs(now-s[r[j]].l);
			now=s[r[j]].l;
		}
		s[r[j]].u=true;
		while(s[l[i]].u&&i<=n)i++;
		if(i>n)break;
		if(!(s[l[i]].l<=now&&s[l[i]].r>=now)){
			ans+=std::abs(now-s[l[i]].r);
			now=s[l[i]].r;
		}
		s[l[i]].u=true;
	}
	ans+=std::abs(now);
	#undef ans
	printf("%lld",std::max(ans1,ans2));
} 