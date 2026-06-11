#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000005;
int a[N],b[N],c[N],d[N];
int n,k,q;
int main()
{
	//freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans=0x3f3f3f3f;
	cin >>n>>k>>q;
	for(int i=1;i<=n;i++)cin >>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		int tmp=0;
		for(int j=1;j<=n;j++)
			b[j]=a[j];
		for(int j=1;j<=n;j++)if(a[j]<a[i])c[j]=1;
		//for(int j=1;j<=n;j++)cout <<c[j]<<' ';cout <<endl;
		for(int j=1;j<=n;j++)
		{
			if(!c[j])
			{
				int l=j,r=l;
				while(!c[r+1]&&r+1<=n)r++;
				//cout <<l<<' '<<r<<endl;
				if(r-l+1<k){j=r+1;continue;}
				sort(b+l,b+r+1);
				for(int tmp1=l;tmp1<=r-k+1;tmp1++)d[++tmp]=b[tmp1];
				j=r+1;
			}
		}
		sort(d+1,d+1+tmp);
		//for(int j=1;j<=tmp;j++)cout <<d[j]<<' ';cout <<endl;
		if(tmp>=q)ans=min(ans,d[q]-d[1]);
		//cout <<tmp<<' '<<d[q]-d[1]<<endl;
		//cout <<ans<<endl;
		//cout <<endl;
	}
	cout <<ans<<endl;
	return 0;
}