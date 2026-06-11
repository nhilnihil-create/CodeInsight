#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n,k,q,a[2005],c[2005],bit[2005],ans=1e9;
set<int>s;
void upd(int x){for(;x<=n;x+=x&-x)bit[x]++;}
int qry(int x){int r=0;for(;x;x-=x&-x)r+=bit[x];return r;}
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),c[i]=i;
	sort(c,c+n,cmp);
	for(int i=0;i+q<=n;i++)
	{
		int cnt=0;memset(bit,0,sizeof(bit));
		for(int j=i;j<n;j++)
		{
			int x=c[j],lp,rp;
			set<int>::iterator l=s.lower_bound(x),r=l;
			lp=(l!=s.begin()?(*--l):-1);rp=(r!=s.end()?(*r):n);
			if(rp-lp-1-(qry(rp)-qry(lp+1))>=k)upd(x+1),cnt++;
			if(cnt>=q){ans=min(ans,a[c[j]]-a[c[i]]);break;}
		}
		s.insert(c[i]);
	}
	printf("%d\n",ans);
	return 0;
} 