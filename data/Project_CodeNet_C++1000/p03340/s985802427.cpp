#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
#include <numeric> //lcm
#include <iomanip> //double精度 setprecision

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define all(vec) (vec).begin(),(vec).end()

#define debug(vec) for(auto v : vec) cout << v << " "; cout << endl;
#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cout << v << " "; cout << endl; } 
#define debugP(vec) for(auto v : vec) cout << "(" << v.first << "," << v.second << ") "; cout << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cout << "(" << v.first << "," << v.second << ") "; cout << endl; } 

typedef long long ll;

constexpr ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
constexpr ll MOD = 1000000007;

template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } else return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }

int main() {
		int n; cin >> n;
		vector<int> a(n);
		rep(i,n) cin >> a[i];

		vector<int> digit(20,0);

		ll ans = 0;
		int r = 0;
		rep(l, n) {
			while (r < l) r++;
			bool ok = true;
			if (r < n) rep(i,20) if (a[r] >> i & 1 && digit[i] >= 1) ok = false;
			while (r < n && ok) {
				rep(i, 20) if (a[r] >> i & 1) digit[i]++;
				r++;
				if (r < n) rep(i, 20) if (a[r] >> i & 1 && digit[i] >= 1) ok = false;
			}

			ans += (r-l);

			rep(i, 20) if (a[l] >> i & 1) digit[i]--;
		}
		cout << ans << endl;
}