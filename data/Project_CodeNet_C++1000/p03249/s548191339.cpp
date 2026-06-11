#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n; ll d[1 << 17];
vector<int> G[1 << 17];
ll c[1 << 17];
vector<LP> v;
map<ll, int> mp;

ll h[1 << 17];
ll calc(int id) {
	h[id] = 1;
	ll res = 0;
	rep(j, G[id].size()) {
		int to = G[id][j];
		res += calc(to); h[id] += h[to];
	}
	return res + h[id];
}
int main() {
	bool valid = true;
	cin >> n;
	rep1(i, n) {
		cin >> d[i]; v.push_back({ d[i],i });
		mp[d[i]] = i;
	}
	sort(v.begin(), v.end(), greater<LP>());
	rep(i, n - 1) {
		int id = v[i].second;
		ll nexval = v[i].first - (n-2-2 * c[id]);
		int t = mp[nexval];
		if (t==0||nexval>=v[i].first) {
			valid = false; break;
		}
		else {
			G[t].push_back(id);
			c[t] += c[id] + 1;
		}
	}
	if (!valid)cout << -1 << endl;
	else {
		ll s = calc(v[n-1].second) - n;
		//cout << "hael" << endl;
		/*cout << s << endl;
		cout << v[n - 1].first << endl;*/
		if (s != v[n - 1].first) {
			cout << -1 << endl;
		}
		else {
			rep1(i, n) {
				rep(j, G[i].size()) {
					cout << i << " " << G[i][j] << endl;
				}
			}
		}
	}
	//stop
	return 0;
}
