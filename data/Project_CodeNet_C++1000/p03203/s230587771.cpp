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
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct point
{
	long long x; long long y;
	bool operator<(const point& rhs) const {
		if (y != rhs.y) {
			return y < rhs.y;
		}
		else {
			return x < rhs.x;
		}
	}
};

ll const MAX = 200005;
point p[MAX];


int main() {
	ll w, h, n;
	cin >> h >> w >> n;
	ll ans = h;
	REP(i, 1, n) {
		ll x, y;
		cin >> x >> y;
		p[i] = { x,y };
	}
	sort(p + 1, p + 1 + n);
	ll pen = 0;
	REP(i, 1, n) {
		point cur = p[i];
		ll curx = cur.x; ll cury = cur.y;
		//cout << curx << " # " << cury << " " << " ";
		if (curx - 1  >= cury + pen) {
			ans = min(ans, curx - 1);
			//cout << '&' << " ";
			if (ans == curx - 1) {
				//cout << "!";
			}
		}
		if (curx == cury + pen) {
			pen++;
			//cout << "?";
		}
		//cout << endl;
	}
	cout << ans << endl;
}