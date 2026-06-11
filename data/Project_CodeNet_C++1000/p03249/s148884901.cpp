#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
#include<set>
#include<cstdlib>
typedef long long ll;
int n;
ll d[111111];
struct pii
{ll x,len;int p,s;};
bool operator<(cpnst pii x,cpnst pii y)
{return x.x<y.x;}
void throwb()
{puts("-1"),exit(0);}
std::multiset<pii>s;
void push(ll x,ll l,int y,int z)
{s.insert(pii{x,l,y,z});}
void pop(ll x,ll l,int y,int z)
{s.erase(s.find(pii{x,l,y,z}));}
void push(pii g)
{s.insert(g);}
void pop(pii g)
{s.erase(s.find(g));}
int x[111111],y[111111];
void print()
{for(register int i=1;i<n;i++)printf("%d %d\n",x[i],y[i]);}
#include<vector>
std::vector<int>v[111111];
ll check(ll s,ll dis=0)
{
	ll ret=dis;
	for(auto t:v[s])
		ret+=check(t,dis+1);
	return ret;
}
int main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",d+i),push(d[i],0,i,1);
	for(i=n-1;i;i--)
	{
		pii rem=*--s.end();
		ll tp=d[rem.p]+2*rem.s-n;
		pii reg=*s.lower_bound(pii{tp,0,0,0});
		if(reg.x^tp)throwb();
		pop(rem);
		if(s.find(reg)==s.end())throwb();
		pop(reg);
		x[i]=rem.p,y[i]=reg.p;
		v[y[i]].push_back(x[i]);
		reg.len+=rem.len+rem.s,reg.s+=rem.s;
		push(reg);
	}int rt=(*--s.end()).p;
	if(check(rt)!=(*--s.end()).x)throwb();
	print();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/