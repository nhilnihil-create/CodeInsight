#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n)
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define var(n) int n; scn(n)
#define F first
#define S second 
#define pb(n) push_back(n)
#define pii pair<int,int> 
#define all(x) (x).begin(),(x).end()
const int N=1e5+5;
const ll M=1e9+7;
const ll inf=1e18+5;

vector<int> g[N];

int main()
{
	var(n);var(m);
	rep(i,0,m)
	{
		var(x);var(y);
		if(x>y)
			swap(x,y);
		g[x].push_back(y);
	}	
	for(int i=0;i<N;i++)
	{
		sort(all(g[i]));		
	}
	// for(int i = 0;i<=n;i++)
	// {
	// 	if(!g[i].empty())
	// 		printf("%d %d\n",i,g[i][0]);
	// }
	
	vector<pair<int,int>> vp;
	int l = -1,r = -1;
	
	for(int i = 1;i<n;i++)
	{
		if(!g[i].empty())
		{
			int new_l = i;
			int new_r = g[i][0];

			if(l== -1)
			{
				l = new_l;
				r = new_r;
			}
			else
			{
				if(r > new_l)
				{
					l = max(l,new_l);
					r = min(r,new_r);
				}
				else
				{
					vp.push_back({l,r});
					l = new_l;
					r = new_r;
				}
			}
		}
	}
	vp.push_back({l,r});
	pri((int)vp.size());
	// for(auto it:vp)
	// {
	// 	printf("%d %d\n",it.F,it.S);
	// }
}