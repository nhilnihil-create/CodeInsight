#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define pi 3.14159265359
#define mp make_pair
#define ff first
#define ss second
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define pf printf
#define sz(a) (ll)(a.size())
#define psf push_front
#define ppf pop_front
#define ppb pop_back
#define pb push_back
#define pq priority_queue
#define all(s) s.begin(),s.end()
#define sp(a) setprecision(a)
#define rz resize
#define ld long double

using namespace std;

vector<vector<ll> > dp;

bool cmp(const pair<int,pair<int,int> > &a,const pair<int,pair<int,int> > &b)
{
	return a.ff+a.ss.ff<b.ff+b.ss.ff;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int,pair<int,int> > > p(n);
	int val[n],w=0;
	f(i,0,n)
	{
		cin>>p[i].ff>>p[i].ss.ff>>p[i].ss.ss;
		w+=p[i].ff;
	}
	dp.rz(n+1,vector<ll> (20202));
	sort(all(p),cmp);
	f(i,1,n+1)
		dp[i][0]=0;
	f(i,1,20202)
		dp[0][i]=0;
	dp[0][0]=0;
	// f(i,0,n)
	// 	cout<<p[i].ff<<' '<<p[i].ss.ff<<' '<<p[i].ss.ss<<"\n";
	f(i,1,n+1)
	{
		f(j,p[i-1].ff,20202)
		{
			if(p[i-1].ss.ff>=j-p[i-1].ff)
				dp[i][j]=max(dp[i-1][j],p[i-1].ss.ss+dp[i-1][j-p[i-1].ff]);
			dp[i][j-p[i-1].ff]=max(dp[i][j-p[i-1].ff],dp[i-1][j-p[i-1].ff]);
		}
	}
	// cout<<dp[n][w]<<"\n";
	ll mx=-1;
	// f(i,0,n+1)
	// {
	// 	f(j,0,w+1)
	// 		cout<<dp[i][j]<<' ';
	// 	cout<<"\n";
	// }
	f(i,1,20202)
		mx=max(mx,dp[n][i]);
	cout<<mx<<"\n";
}