#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, b) for (int i = 0; i < b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define ppi pair<int,int>
#define scl(n) scanf("%d",&n);
#define pcl(n) printf("%d\n", n)
#define pcl1(n) printf("%lld ", n)
#define FastRead                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(0)
bool comp(ppi a,ppi b)
{
	return a.first<b.first;
}

int main()
{
	int n,m,i=1,res=0;
	cin>>n>>m;
	ppi p;
	vector<ppi>v;
	while(n--)
	{
		scl(p.first);
		scl(p.second);
		if(p.second<=m) v.pb(p);
	}
	if(v.size()<1) 
	{
		cout<<"TLE\n";
		return 0;
	}
	else
	{
		sort(v.begin(),v.end(),comp);
		cout<<v[0].first<<endl;
	}
	return 0;
}