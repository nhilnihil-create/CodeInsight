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
const int N=2e5+5;
const ll M=1e9+7;
const ll inf=1e18+5;


int main()
{
	var(n);
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		var(x);
		ans+=x-1;
	}
	lpri(ans);
}