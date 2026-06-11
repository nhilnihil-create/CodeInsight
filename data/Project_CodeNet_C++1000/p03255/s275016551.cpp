#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define tr(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define MEMS(x,t) memset(x,t,sizeof(x));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
//#define MOD 1000000007
#define endl "\n" 
#define int long long
#define inf 9e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/
 
int32_t main()
{
	fastio();
	int n;
	int X;
	cin>>n>>X;
	int ar[n+1];
	int cum[n+1];
	MEMS(cum,0);
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		cum[i]=cum[i-1]+ar[i];
	}
	vector<int> v;
	v.push_back(5);
	v.push_back(5);
	while(v.size()<n+5)
	{
		int tmp=v.back();
		v.push_back(tmp+2);
	}
	int ans=inf;
	for(int siz=n;siz>=1;siz--)
	{
		int pt=n;
		int c=0;
		__int128 cur=0;
		__int128 one=1;
		while(pt>=1)
		{
			cur+=one*v[c++]*(cum[pt]-cum[max(0LL,pt-siz)]);
			pt-=siz;
		}
		cur+=n*X+siz*X;
		if(cur>1e18)continue;
		ans=min(ans,(int)cur);
	}
	cout<<ans<<endl;
}
