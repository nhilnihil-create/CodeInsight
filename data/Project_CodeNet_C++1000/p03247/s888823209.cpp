//W4P3R
#include<bits/stdc++.h>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
#define pb push_back
#define re register ll
#define fr first
#define sd second
#define pa pair<ll,ll>
#define FOR(i,a,b) for(re i=a;i<=b;i++)
#define REP(i,a,b) for(re i=a;i>=b;i--)
#define lowbit(x) (x&(-x))
#define Z(x) (x>=mod?x-mod:x)
#define N 1010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
ll n;
ll x[N],y[N];
ll len[N],tot;
ll flag;
int main()
{
	//ios::sync_with_stdio(false);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	FOR(i,1,n)x[i]=read(),y[i]=read();
	flag=abs(x[1]+y[1])&1;
	FOR(i,1,n)if((abs(x[i]+y[i])&1)^flag){puts("-1");return 0;}
	printf("%lld\n1 ",32-flag);
	len[tot=1]=1;
	if(!flag){FOR(i,0,30){len[++tot]=(1<<i);printf("%d ",(1<<i));}}
	else {FOR(i,1,30){len[++tot]=(1<<i);printf("%d ",(1<<i));}}
	puts("");
	FOR(i,1,n)
	{
		ll nowx=0,nowy=0;
		string s;
		REP(j,tot,1)
		{
			ll dx=x[i]-nowx,dy=y[i]-nowy;
			if(abs(dx)>abs(dy)){dx<0?(s+='L',nowx-=len[j]):(s+='R',nowx+=len[j]);}
			else {dy<0?(s+='D',nowy-=len[j]):(s+='U',nowy+=len[j]);}

		}			
		reverse(s.begin(),s.end());
		cout<<s<<endl;
		//cout<<endl;
	}
	return 0;
}
//check first submit second
