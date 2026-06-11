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


struct edge
{
	long long to; long long len;
	bool operator<(const edge& rhs) const {
		return len > rhs.len;
	}
};
ll const MAX = 1e3 + 5;
ll x[MAX];
ll y[MAX];
ll len[MAX];
ll mx[MAX][MAX], my[MAX][MAX];

ll const ARMS = 36;
void f(ll z[], ll mz[MAX][MAX], ll k) {
	ll val = z[k];
	//cout << z[k] << endl;
	PER(i,  ARMS-1, 0) {
		if (val > 0) {
			mz[k][i] = -1;
			val -= len[i];
		}
		else {
			mz[k][i] = 1;
			val += len[i];
		}
	//	cout << val << endl;
	}
	//cout << "?" << endl;
}

char g(ll i, ll j) {
	ll u = mx[i][j] * 2 + my[i][j] * 1;
	if (u == 3) {
		return 'L';
	}
	else if (u == 1) {
		return 'U';
	}
	else if (u == -1) {
		return 'D';
	}
	else {
		return 'R';
	}
}

int main() {
	cin.tie(0);
	ll n; cin >> n;
	REP(i, 1, n) {
		ll a,b;
		cin >> a >> b;
		x[i] = a - b;
		y[i] = a + b;
		if ((x[i] + x[1]) % 2 == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	REP(i, 0,  ARMS-1) {
		len[i] = BIT(i);
	}
	bool eve = 0;
	if (x[1] % 2 == 0) {
		eve = 1;
		REP(i, 1, n) {
			x[i]++;
			y[i]++;
		}
	}
	REP(i, 1, n) {
		f(x, mx, i);
		f(y, my, i);
	}
	cout << ARMS + eve << endl;
	REP(i, 0,  ARMS-1) {
		cout << len[i];
		if (i <  ARMS-1) {
			cout << " ";
		}
	}
	if (eve) {
		cout << " " << 1;
	}
	cout << endl;
	REP(i, 1, n) {
		REP(j, 0,  ARMS-1) {
			cout << g(i, j);
		}
		if (eve) {
			cout << "L";
		}
		cout << endl;
	}
}