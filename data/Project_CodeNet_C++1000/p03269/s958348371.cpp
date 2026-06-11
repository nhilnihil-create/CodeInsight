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
#define vvll vector<vector<ll>>
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct edge
{
	long long to; long long len;
	bool operator<(const edge& rhs) const {
		return len > rhs.len;
	}
};

ll yowayowa = 0;

ll powo(ll x, ll y) {
	ll ans = 1;
	REP(i, 1, y) {
		ans *= x;
	}
	return ans;
}


ll const MAX = 30;
vector<vector<edge>> G(MAX);

vll u(30);

int main() {
	REP (i, 0, 24) {
		u[i] = powo(2, i - 1) - 1;
	}
	ll n;
	cin >> n;
	n--;
	ll goal = 1;
	ll m = 0;
	while (powo(2, goal) - 1 <= n) {
		G[goal].push_back({ goal + 1, powo(2,goal - 1) });
		G[goal].push_back({ goal + 1,0 });
		goal++;
		m += 2;
	}
	ll s = u[goal];
	while (s < n) {
		ll tmp = 0;
		while (u[tmp + 1] < n - s) {
			tmp++;
		}
		G[tmp].push_back({ goal, s + 1 });
		m++;
		s += u[tmp] + 1;
	}
	cout << goal << " " << m << endl;
	REP(i, 1, goal) {
		for (auto x : G[i]) {
			cout << i << " " << x.to << " " << x.len << endl;
		}
	}
	

}