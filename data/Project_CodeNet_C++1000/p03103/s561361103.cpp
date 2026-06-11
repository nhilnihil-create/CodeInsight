#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;  
#define mp make_pair
#define pb push_back

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	vector < pair<ll,int> > v;	
	ll a;int b;
	for (int i = 0; i < n; i++)
	{
		cin>>a>>b; v.pb(mp(a,b));
	}
	sort(v.begin(),v.end());
	int cnt = 0;
	ll cost = 0;
	for (int i = 0; i < n; i++)
	{
		if(cnt+v[i].second <= m)
		{
			cnt+=v[i].second;
			cost+= v[i].first * v[i].second;
			if(cnt == m)return cout<<cost,0;
		}
		else //if(cnt+v[i].second > m)
		{
			cost+= (m-cnt) * v[i].first;
			return cout<<cost,0;
		}
	}
}