#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int max_bit = 29;

	int n;
	cin >> n;

	vector<int> a;
	vector<int> b;

	rep(i,n){
		int t;
		cin >> t;
		a.push_back(t);
	}

	rep(i,n){
		int t;
		cin >> t;
		b.push_back(t);
	}

	int ans = 0;
	rep(k,max_bit){
		vector<int> v;
		rep(i,n){
			v.push_back(b[i] % (1 << (k+1)));
		}

		sort(v.begin(), v.end());

		int t = 1 << k;
		rep(i,n){
			int x = a[i] % (1 << (k+1));

			auto c = lower_bound(v.begin(), v.end(), t - x);
			auto d = lower_bound(v.begin(), v.end(), 2 * t - x);
			auto e = lower_bound(v.begin(), v.end(), 3 * t - x);
			auto f = lower_bound(v.begin(), v.end(), 4 * t - x);

			ans ^= t * ((distance(c, d) + distance(e, f)) & 1);
		}
	}

	cout << ans << endl;
}