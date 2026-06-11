#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=(s);i<(t);++i)
#define repb(i,s,t) for(int i=(s);i<=(t);++i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
#define mst(a,b) memset(a,b,sizeof(a))
#define dd(x) cout<<#x<<'='<<x<<' '
#define de(x) cout<<#x<<'='<<x<<'\n'
#define fi first
#define se second
#define sq(x) ((x)*(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

const int inf = 0x3f3f3f3f;
const ll infl = 4557430888798830399ll;
const ll mod = 1e9+7;


int main()
{
	int T;
	ll a,b,c,d,g;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(d<b||a<b)printf("No\n");
		else if(b<=c)printf("Yes\n");
		else 
		{
			a%=b;d%=b;
			g=__gcd(b,d);
			if((b+b-a-1)/g-(b+c-a)/g>0||(b+c-a<0&&b+b-a>0))printf("No\n");
			else printf("Yes\n");
		}
	}
}