#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long
#define upperlimit 1000100
#define INF 1e18
#define eps 1e-8
#define endl '\n'
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define MOD 1000000007LL
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>
#define vll vector<ll>
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define csl ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
ll gcd(ll n1,ll n2){
	if(n2==0)
		return n1;
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
	if(exponent<0) exponent+=MOD-1;
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%MOD;
		base=(base*base)%MOD;
		exponent/=2;
	}
	return ans;
}
string s;
bool flag=false;
vector<int> v[MAX];
int visited[MAX][4];
void DFS(int n,int p)
{
	if(visited[n][p]==2)
		return;
	if(visited[n][p]==1)
	{
		flag=true;
		return;
	}
	visited[n][p]=1;
	if(p==0||p==3)
	{
		for(auto j:v[n])
			if(s[j]=='A')
			DFS(j,(p+1)%4);
	}
	else
	{
		for(auto j:v[n])
			if(s[j]=='B')
			DFS(j,(p+1)%4);
	}
	visited[n][p]=2;
}
int main()
{
	csl;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='A')
			DFS(i,0);
	}
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}