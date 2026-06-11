#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x)(x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long n,m,i,j,x[1005],y[1005],s=1,a[45],zhi[45],cnt=0,cnt2;
map<long long,char> mp;
void prt(long long t1,long long t2,long long yy)
{
	if (yy==0)
	{
		if (t1||t2)
		{
			puts("-1");
			exit(0);
		}
		return;
	}
	if (abs(t1)>abs(t2))
	{
		if (t1<0)
		{
			a[yy]=-1;
			t1+=zhi[yy];
		}
		else
		{
			a[yy]=1;
			t1-=zhi[yy];
		}
	}
	else
	{
		if (t2<0)
		{
			a[yy]=-2;
			t2+=zhi[yy];
		}
		else
		{
			a[yy]=2;
			t2-=zhi[yy];
		}
	}
	prt(t1,t2,yy-1);
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		if (i!=1)
		{
			if (((x[i]+y[i]-x[1]-y[1])%2+2)&1)
			{
				puts("-1");
				return 0;
			}
		}
	}
	mp[2]='U';
	mp[-2]='D';
	mp[1]='R';
	mp[-1]='L';
	if ((((x[1]+y[1])%2+2)%2)==0)
	{
		cnt=1;
		zhi[1]=1;
	}
	for (i=1;i<=20;i++)
	{
		zhi[++cnt]=s;
		if (i!=20) zhi[++cnt]=s;
		/*if (i!=1)*/ s*=3;
	}
	cout<<cnt<<endl;
	for (i=1;i<=cnt;i++)
	{
		cout<<zhi[i];if (i!=cnt) cout<<' ';
	}
	cout<<endl;
	for (i=1;i<=n;i++)
	{
		memset(a,0,sizeof(a));prt(x[i],y[i],cnt);for (j=1;j<=cnt;j++) cout<<mp[a[j]];
		cout<<endl;
	}
	return 0;
}
