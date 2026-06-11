#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#include<math.h>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;
double const PI = 3.1415926535;

struct edge
{
	long long to; long long cost;
	bool operator<(const edge& rhs) const {
		return cost > rhs.cost;
	}
};

ll const MAX = 2e5 + 5;
ll a[MAX], b[MAX];

int main(){
	ll flag = 1;
	ll n;
	cin >> n;
	REP(i, 1, n) {
		cin >> a[i] >> b[i];
		if (a[i] != b[i]) {
			flag = 0;
		}
	}
	if (flag) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	ll b_min = 1e18;
	REP(i, 1, n) {
		if (a[i] > b[i]) {
			b_min = min(b_min, b[i]);
		}
		ans += b[i];
	}
	cout << ans - b_min << endl;
}