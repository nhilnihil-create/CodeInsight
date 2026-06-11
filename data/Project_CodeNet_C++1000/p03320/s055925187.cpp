#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll p[20],b[20];

inline double S(ll x)
{
	ll tmp=0,tmp2=x;
	while(x) tmp+=(x%10),x/=10;
	//cout<<tmp2<<" "<<(double)tmp2/(double)tmp<<endl;
	return (double)tmp2/(double)tmp;
}

int main()
{
	//freopen("t1.in","r",stdin);
	ll k=read(); p[0]=0; b[0]=1;
	for(int i=1;i<=15;i++) p[i]=(p[i-1]+1)*10-1;
	for(int i=1;i<=15;i++) b[i]=b[i-1]*10;
	int nw=0,c1=1,cnt=0;
	while(cnt<k)
	{
		if(S(c1*b[nw]+p[nw])<=S((c1+1)*b[nw]+p[nw]))
		{
			cout<<c1*b[nw]+p[nw]<<endl; c1++; cnt++;
		}
		else nw++,c1=c1/10;
	}
	return 0;
}