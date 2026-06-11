#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fi first
#define se second
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, a[N], cnt[35];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	ll ans = 0;
 	int l = 0;
	for(int i=1; i<=n; i++)
	{	
		bool ok = 1;
		for(int j=0; j<=30; j++)
		{
			if((a[i]>>j)&1) 
			{
				cnt[j]++;
				if(cnt[j]>1) ok = 0;
			}
		}
		if(ok) ans += i - l;
		else
		{
			for(l=l+1; l<=i;l++)
			{
				for(int k=0; k<=30; k++)
				{
					if((a[l]>>k)&1) cnt[k]--;
				}
				bool ok = 1;
				for(int k=0; k<=30; k++)
					if(cnt[k]>1) ok = 0;
				if(ok) break;
			}
			ans += i - l;
		}
	}
	printf("%lld\n", ans);
	return 0;
}