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
#define MOD 1000000007
#define endl "\n" 
#define int long long
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/

int32_t main()
{
	fastio();
	int n,c;
	cin>>n>>c;
	int x[n],v[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>v[i];
	}
	int fm[n];
	int bm[n];
	int totc=0;
	int ma=0;
	for(int i=0;i<n;i++)
	{	
		totc+=v[i];
		fm[i]=max(ma,totc-x[i]);
		ma=fm[i];
	}
	totc=0;
	ma=0;
	for(int i=n-1;i>=0;i--)
	{
		totc+=v[i];
		bm[i]=max(ma,totc-(c-x[i]));
		ma=bm[i];
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,fm[i]);
		ans=max(ans,bm[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		ans=max(ans,fm[i]-x[i]+bm[i+1]);
	}
	for(int i=n-1;i>0;i--)
	{
		ans=max(ans,bm[i]-(c-x[i])+fm[i-1]);
	}
	cout<<ans<<endl;
}
