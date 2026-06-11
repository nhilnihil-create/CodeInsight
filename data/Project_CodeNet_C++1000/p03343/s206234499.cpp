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

int n, k, q;
vector<ll>a;
vector<ll>b;
int check(int mi, int ma) {
	int cnt = 0;
	int tmp = 0;
	int l = 0;
	rep(i, 0, n) {
		if (mi<=a[i]) {
			tmp += (a[i] <= ma);
			l++;
		}
		else {
			if(l >= k)cnt += (l-tmp+1 >= k)?tmp:max(l-k+1,0);
			tmp = 0;
			l = 0;
		}
	}
	if(l >= k)cnt += (l - tmp + 1 >= k) ? tmp : max(l - k + 1, 0);
	return cnt >= q;
}
int main() {
	cin >> n >> k >> q;
	a.resize(n);
	b.resize(n);
	rep(i, 0, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(all(b));

	ll ans = inf;
	rep(i, 0, n) {
		if (!check(a[i],b[n-1]))continue;
		if (check(a[i], a[i]))ans = 0;
		int ng = lower_bound(all(b),a[i])-b.begin(), ok = n - 1;
		while (ok - ng > 1) {
			int mid = (ok + ng) / 2;
			if (check(a[i], b[mid]))ok = mid;
			else ng = mid;
		}
		ans = min(ans,b[ok]-a[i]);
	}
	puts(ans);

	return 0;
}
