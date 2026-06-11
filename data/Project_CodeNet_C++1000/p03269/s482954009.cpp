#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int b[maxn],t[maxn],ans,d;
vector <int> a1,a2,a3;

int main()
{
	int L=read()-1,base=1,cnt=0,d=L;
	while(L>0)
	{
		if(L<base) break; L-=base;
		b[++cnt]=base,t[cnt]=base*2-1; base<<=1;
	}
	ans=cnt*2; int res=b[cnt]*2;
	for(int i=1,j=cnt;i<=j;i++,j--) swap(b[i],b[j]),swap(t[i],t[j]);
	for(int i=1;i<=cnt;i++)
	{
		//cout<<L<<" "<<i<<" "<<t[i]<<endl;
		if(res+t[i]<=d)
		{
			a1.push_back(1); a2.push_back(i); a3.push_back(res);
			ans++; res+=(t[i]+1);
			//cout<<"Asjldas"<<endl;
		}
	}
	if(res<=d) a1.push_back(1),a2.push_back(cnt+1),a3.push_back(d),ans++;
	cout<<cnt+1<<" "<<ans<<endl;
	for(int i=1;i<=cnt;i++)
	{
		printf("%d %d %d\n",i,i+1,b[i]);
		printf("%d %d %d\n",i,i+1,0);
	}
	for(int i=0;i<a1.size();i++) printf("%d %d %d\n",a1[i],a2[i],a3[i]);
	return 0;
}