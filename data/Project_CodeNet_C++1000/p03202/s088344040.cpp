#include<map>
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

/*
struct point
{
long long dist; long long name;
bool operator<(const point& rhs) const {
return dist > rhs.dist;
}
};
*/

ll const MAX = 200005;
ll a[MAX];
ll n;

bool ok(ll x) {
	if (x == 1) return false;
	vector<ll> v, u;
	v.push_back(0);//keta
	u.push_back(0);//suuji

	REP(i, 1, n) {
		ll t = v.back();
		bool flag = 0;
		while (t > a[i]) {
			v.pop_back();
			u.pop_back();
			t = v.back();
			flag = 1;
		}	
		
		if (t < a[i]) {
			v.push_back(a[i]);
			u.push_back(1 + flag);
		}
		else if (t == a[i]) {
			ll s = a[i];
			while (s == v.back() && x == u.back()) {
				v.pop_back();
				u.pop_back();
				s--;
				flag = 1;
				if (s == 0) {
					return false;
				}
			}
			if (s == v.back()) {
				u[SIZE(u) - 1]++;
			}
			else {
				v.push_back(s);
				u.push_back(2);
			}
		}
	}
	return true;
}

int main() {
	cin >> n;
	bool flag = 1;
	cin >> a[1];
	REP(i, 2, n) {
		cin >> a[i];
		if (a[i - 1] >= a[i]) {
			flag = 0;
		}
	}
	if (flag) {
		cout << 1 << endl;
		return 0;
	}
	ll ub = 1e18; ll lb = 1;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		if (!ok(mid)) {
			lb = mid;
		}
		else {
			ub = mid;
		}
	}
	cout << ub << endl;
}