#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<pair<ii,int> > edges;
int n;

void add(int u, int v, int c)
{
	edges.pb(mp(mp(u+1,v+1),c)); n=max(n,u+1); n=max(n,v+1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int L; cin>>L;
	vi dig;
	while(L)
	{
		dig.pb(L&1); L>>=1;
	}
	reverse(dig.begin(),dig.end());
	L=1;
	for(int i=1;i<dig.size();i++)
	{
		add(i-1,i,L); add(i-1,i,0);
		L*=2;
		if(dig[i]) {add(0,i,L); L++;}
	}
	cout<<n<<' '<<edges.size()<<'\n';
	for(auto X:edges)
	{
		cout<<X.fi.fi<<' '<<X.fi.se<<' '<<X.se<<'\n';
	}
}
