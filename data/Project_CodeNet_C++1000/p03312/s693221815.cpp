
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

ll sum[202020];
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, n)sum[i + 1] += sum[i]+a[i];


	ll ans = inf;
	for (int c = 1; c <= n-3; c++) {
		ll sum1 = sum[c + 1];
		ll sum2 = sum[n] - sum1;
		ll p, q, r, s;
		//left
		if (a[0] > sum1-a[0]) {
			p = a[0];
			q = sum1 - a[0];
		}
		else {
			int ok = 0;
			int ng = c;
			while (ng - ok > 1) {
				int mid = (ok + ng) / 2;
				if (sum[mid + 1] <= sum1 - sum[mid + 1])ok = mid;
				else ng = mid;
			}
			ll diff1 = abs(sum[ok+1] - (sum1-sum[ok+1]));
			ll diff2 = abs(sum[ok+2] - (sum1-sum[ok + 2]));
			if (diff1 <=  diff2) {
				p = sum[ok + 1];
				q = sum1 - sum[ok + 1];
			}
			else {
				p = sum[ok + 2];
				q = sum1 - sum[ok + 2];
			}
		}
		//right
		if (a[c+1] > sum2 - a[c+1]) {
			r = a[c+1];
			s = sum2 - a[c+1];
		}
		else {
			int ok = c+1;
			int ng = n-1;
			while (ng - ok > 1) {
				int mid = (ok + ng) / 2;
				if (sum[mid+1]-sum[c+1] <= sum2 - sum[mid + 1]+sum[c+1])ok = mid;
				else ng = mid;
			}
			ll diff1 = abs(sum[ok + 1]-sum[c+1] - (sum2 - sum[ok + 1]+sum[c+1]));
			ll diff2 = abs(sum[ok + 2]-sum[c+1] - (sum2 - sum[ok + 2]+sum[c+1]));
			if (diff1 <= diff2) {
				r = sum[ok + 1]-sum[c+1];
				s = sum2 - r;
			}
			else {
				r = sum[ok + 2]-sum[c+1];
				s = sum2 - r;
			}
		}
		vector<ll>v;
		v.pb(p);
		v.pb(q);
		v.pb(r);
		v.pb(s);
		sort(all(v));
		ans = min(ans, v[3] - v[0]);
	}
	puts(ans);

	
	return 0;
}
