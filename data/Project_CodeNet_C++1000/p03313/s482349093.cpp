#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[1<<18];
pair<Pi,Pi> d[1<<18];
pair<Pi,Pi> res(pair<Pi,Pi> ori,pair<Pi,Pi> ne)
{
	pair<Pi,Pi> p=ori;
	if(p.X.X<ne.X.X)
	{
		p.Y=p.X;
		p.X=ne.X;
	}
	else if(p.Y.X<ne.X.X)
	{
		if(p.X.Y!=ne.X.Y)
			p.Y=ne.X;
	}
	if(p.Y.X<ne.Y.X)
	{
		if(p.X.Y!=ne.Y.Y)
			p.Y=ne.Y;
	}
	return p;
}
int main() {
	fill(d,d+(1<<18),mp(mp(-1,-1),mp(-1,-1)));
	int n;
	scanf("%d",&n);
	fup(i,0,(1<<n)-1,1)scanf("%d",a+i);
	fup(i,1,(1<<n)-1,1)
	{
		auto t=mp(mp(a[0],0),mp(a[i],i));
		if(t.X<t.Y)swap(t.X,t.Y);
		d[i]=res(d[i],t);
		fup(j,0,n-1,1)
		{
			if(!(i&(1<<j)))d[i+(1<<j)]=res(d[i+(1<<j)],d[i]);
		}
	}
	int ans=0;
	fup(i,1,(1<<n)-1,1)
	{
		pair<Pi,Pi> p=d[i];
		ans=max(ans,p.X.X+p.Y.X);
		printf("%d\n",ans);
	}
}