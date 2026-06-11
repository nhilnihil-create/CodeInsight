//******\\
**udc321**	 
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define fr(e,r,v) for(int e=r;e<v;e++)
#define bc(e,r,v) for(int e=r;e>v;e--)
#define all(n) (n.begin(),n.end())
#define ft first
#define sd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mpr make_pair
#define db  double
using namespace std;

ll mod=1000000007;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*pair(sort and all) implementation and upper bound implementation*/
int main()
{
	ll n;
	cin>>n;
	ll a[n],b[n],c[n];
	fr(j,0,n)
	{
		cin>>a[j]>>b[j]>>c[j];
		if(j>0)
		{
			a[j]+=max(b[j-1],c[j-1]);
			b[j]+=max(a[j-1],c[j-1]);
			c[j]+=max(a[j-1],b[j-1]);
		}

	}
	cout<<max(max(a[n-1],b[n-1]),c[n-1]);

}







