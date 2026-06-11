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
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct point
{
long long num; long long name;
bool operator<(const point& rhs) const {
	return num < rhs.num;
	}
};


ll const MAX = 2e3+4;

ll a[MAX];
point b[MAX];
ll c[MAX] = {};

int main() {
	cin.tie(0);
	ll n, k, q;
	cin >> n >> k >> q;
	REP(i, 1, n) {
		cin >> a[i];
		b[i] = { a[i],i };
	}
	SORT(b, n);
	ll ans = 1e18;
	c[n + 1] = 1;
	REP(i, 1, n) {
		if (i+q-1 > n) break;	

		//ll x = b[i + q - 1].num - b[i].num;
		//cout << x << endl;
		ll cur = 0;
		ll cnt = 0;
		vll t, s;
		REP(j, 1, n + 1) {
			if (c[j] == 0) {
				cur++;
				t.push_back(a[j]);
			}
			else {
				if (cur >= k) {
					sort(t.begin(), t.end());
					REP(i, 0, cur - k) {
						s.push_back(t[i]);
					}
				}
				cur = 0;
				t.clear();
			}
		}
		if (s.size() >= q) {
			sort(s.begin(), s.end());
			ans = min(ans, s[q - 1] - s[0]);
		}
		else { break; }
		c[b[i].name] = 1;
	}
	cout << ans << endl;
}