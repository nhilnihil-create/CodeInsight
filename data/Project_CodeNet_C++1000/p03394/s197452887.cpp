#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P std::pair<int,int>
#define PiP std::pair<int,std::pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp std::make_pair
#define prique(T) std::priority_queue<T,vector<T>,greater<T>>
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}
int get_rand(int MIN, int MAX) {
	std::random_device rnd;
	std::mt19937 mt32(rnd());
	std::uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt32);
}
/*--------Library Zone!--------*/



signed main() {
	int n; cin >> n;
	if (n == 3) {
		cout << "2 5 63\n";
	}
	else {
		int cnt = 0, sum = 0;
		vector<int>ans;
		for (int i = 2; cnt < n - 1; i++) {
			if (i % 2 == 0 || i % 3 == 0) {
				ans.push_back(i); cnt++; sum += i;
			}
		}
		if (sum % 6 == 1 || sum % 6 == 5) {
			sum -= ans.back(); int i = ans.back() + 1; ans.pop_back();
			for (;; i++) {
				if (i % 2 == 0 || i % 3 == 0) {
					if ((sum + i) % 6 != 1 && (sum + i) % 6 != 5) {
						sum += i; ans.push_back(i); break;
					}
				}
			}
		}
		for (int i = ans.back() + 1;; i++) {
			if (i % 2 == 0 || i % 3 == 0) {
				if ((sum + i) % 6 == 0) {
					ans.push_back(i); break;
				}
			}
		}
		for (int i : ans)cout << i << " "; cout << endl;
	}
}
