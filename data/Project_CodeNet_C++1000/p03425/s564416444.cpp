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
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/
 
int32_t main()
{
	fastio();
	int n;
	cin>>n;
	vector<int> v(5,0);
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(s[0]=='M')
		{
			v[0]++;
		}
		else if(s[0]=='A')
		{
			v[1]++;
		}
		else if(s[0]=='R')
		{
			v[2]++;
		}
		else if(s[0]=='C')
		{
			v[3]++;
		}
		else if(s[0]=='H')
		{
			v[4]++;
		}
	}
	int ans=0;
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			for(int k=j+1;k<5;k++)
			{
				ans+=v[i]*v[j]*v[k];
			}
		}
	}
	cout<<ans<<endl;
}
