#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define rint register int
using namespace std;
inline int read(){int w=1,s=0;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}return w*s;}
int N,x[1000010],y[1000010],f[1000010],H,W;
vector<int> vec[1000010];
int main()
{
	H=read(),W=read(),N=read();
	for(rint i=1;i<=N;++i)
	{
		x[i]=read(),y[i]=read();
		vec[y[i]].pb(x[i]);
	}
	for(rint i=1;i<=W;++i) vec[i].pb(H+1);
//	for(rint i=1;i<=H;++i,cout<<endl)
//	for(rint j=1;j<=W;++j) cout<<vis[i][j]<<" "; 
	for(rint i=1;i<=W;++i)
	{
		sort(vec[i].begin(),vec[i].end());
	}f[1]=1;
	for(rint i=2;i<=W;++i)
	{
		int sz=vec[i].size();
		int tmp=f[i-1]+1;if(tmp==-1) continue;
		for(rint j=0;j<sz;++j)
		{
			int pos=vec[i][j];
			if(pos==tmp) tmp++;
		}
		f[i]=tmp;
	}int ans=1e9;
//	cout<<f[i]<<"\n";
	for(rint i=1;i<=W;++i)
	{
//		cout<<f[i]<<"\n";
		int x=f[i];if(x==-1) continue;
		int cur=lower_bound(vec[i].begin(),vec[i].end(),f[i])-vec[i].begin();
		if(cur<vec[i].size())
		ans=min(vec[i][cur]-1,ans);
	} cout<<ans;
	return 0;
}
