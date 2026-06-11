#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define time_taken_start int begtime = clock();
#define time_taken_end int endtime = clock(); \
cerr << "\n\n" << "Time elapsed: " << \
(endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
return 0;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define inf 1000000000000000007
#define eps 0.0000000001
#define pi acosl(-1)
#define pii pair<int,int>
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vii vector<int>
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset <ll>
#define msetd multiset <ll,greater<ll>>
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound 
#define stp fixed<<setprecision(20)
#define endl '\n'
ll ans[20009];
int main()
{
	FAST
	#ifdef ayk_16
	    time_taken_start
		freopen("input.txt","rt",stdin);
		freopen("output.txt","wt",stdout);
	#endif
	ll n,s,w,v;
	cin>>n;
	pair<ll,pll> p[n];
	for(ll i=0;i<n;i++)
	{
		cin>>w>>s>>v;
		p[i].ff=w+s;
		p[i].ss.ff=s;
		p[i].ss.ss=v;
	}
	sort(p,p+n);
	ll a=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=20000;j>=0;j--)
		{
			if(j<=p[i].ss.ff)
			{
				ll z=p[i].ff-p[i].ss.ff;
				z+=j;
				if(z<=20000)
				{
					ans[z]=max(ans[z],ans[j]+p[i].ss.ss);
				}
			}
		}
	}
	for(ll i=0;i<=20000;i++)
	{
		a=max(a,ans[i]);
	}
	cout<<a;
}