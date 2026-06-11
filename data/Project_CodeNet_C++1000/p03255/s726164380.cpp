#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define rint register int 
using namespace std;
inline ll read(){ll w=1,s=0;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}return w*s;}
ll n,A[1000010],X;
ll Sum[1000010],differ[1000010];
int main()
{
	n=read();X=read();
	for(rint i=1;i<=n;++i) A[i]=read(),Sum[i]=A[i]+Sum[i-1];
	differ[1]=differ[2]=5;
	for(rint i=3;i<=n+100;++i) differ[i]=differ[i-1]+2;
	ll ans=8e18;
	for(rint k=1;k<=n;++k)
	{
		ll res=1ll*k*X;
		for(rint i=n,j=1;i>0&&res<ans;i=max(i-k,0),j++)
		{
			res+=1ll*(Sum[i]-Sum[max(i-k,0)])*differ[j];
		}
	//	cout<<k<<" "<<res<<"\n";
		ans=min(ans,res); 
	}cout<<ans+1ll*n*X<<"\n";
	return 0;
}

