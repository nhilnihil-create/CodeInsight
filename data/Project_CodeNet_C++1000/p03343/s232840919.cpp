#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define ll long long
vector<int>E[2005];
int a[2005],b[2005],n,c[5][2005],mp[2005];
void add(int i,int x,int fg)
{
	while(i<=n)
	{
		c[fg][i]+=x;
		i+=i&(-i);
	}
}
int query(int i,int fg)
{
	int res=0;
	while(i)
	{
		res+=c[fg][i];
		i-=i&(-i);
	}
	return res;
}
int Query(int L,int R,int fg)
{
	return query(R,fg)-query(L-1,fg);
}
int main(int argc, char** argv) {
	int k,q;
	cin>>n>>k>>q;
	rep(i,1,n)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	rep(i,1,n)
	{
		int w=lower_bound(b+1,b+m+1,a[i])-b;
		mp[w]=a[i];
		a[i]=w;	
		E[a[i]].pb(i);
	//	cout<<a[i]<<" "<<i<<endl;
	}
	int mn=1e9;
	rep(i,0,m-1)//最小值取i+1 
	{
		if(E[i].size())
		rep(j,0,E[i].size()-1)
		{
			add(E[i][j],1,1);
		}
		memset(c[2],0,sizeof(c[2]));
		memset(c[3],0,sizeof(c[3]));
		int now=i+1;
		int Q=q,mx=i+1;
		while(now<=m&&Q)
		{
			if(E[now].size())
			rep(j,0,E[now].size()-1)
			{
				//cout<<j<<" "<<now<<"???"<<endl;
				if(!Q)break;
				int l=1,r=E[now][j],L,R;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(Query(mid,E[now][j],1)+Query(mid,E[now][j],2)==0)
					{
						L=mid;
						r=mid-1;
					}
					else l=mid+1;
				}
				l=E[now][j],r=n;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(Query(E[now][j],mid,1)+Query(E[now][j],mid,2)==0)
					{
						R=mid;
						l=mid+1;
					}
					else r=mid-1;
				}
				if(R-L-Query(L,R,3)+1>=k)
				{
			//	if(i==0)	cout<<R<<" "<<L<<"   "<<now<<"   "<<E[now][j]<<" "<<i+1<<endl; 
					mx=now;
					add(E[now][j],1,3);
					Q--;
				}
				else
				{
					add(E[now][j],1,2);
				}
				///cout<<now<<" ?"<<endl;
			}
			now++;
		}
	//	cout<<mx<<" "<<(i+1)<<endl;
		if(Q==0)
		mn=min(mn,mp[mx]-mp[i+1]);
	}
	cout<<mn;
	return 0;
}