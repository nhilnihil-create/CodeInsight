#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

map<int, int> fs;
void prime_factors(int n) {
	if(n == 1) { // n=1 の素因数分解は n^1
		fs[n]++;
		return;
	}
	for(int i = 2, _n = n; i*i <= _n; ++i) {
		while(n % i == 0) {
			++fs[i]; // 素因数i^{res[i]}
			n /= i;
			}
		}
	if(n != 1) fs[n]++; // nが素数のとき
	return;
}

map<int, int> prime_factors2(int n) {
	map<int, int> res;
	if(n == 1) { // n=1 の素因数分解は n^1
		res[n] = 1;
		return res;
	}
	for(int i = 2, _n = n; i*i <= _n; ++i) {
		while(n % i == 0) {
			++res[i]; // 素因数i^{res[i]}
			n /= i;
			}
		}
	if(n != 1) res[n] = 1; // nが素数のとき
	return res;
}

int main() {
	int n; cin >> n;
	FOR(i, 2, n+1) prime_factors(i);
    int s75 = 0, s25 = 0, s15 = 0, s5 = 0, s3 = 0;
	for(const auto& p: fs) {
        if (p.se>=74) s75++;
        if (p.se>=24) s25++;
        if (p.se>=14) s15++;
        if (p.se>=4) s5++;
        if (p.se>=2) s3++;
    }
    debug(s75, s25, s15, s5, s3);
    int ans = 0;
    ans += s75;
    ans += s25 * (s3-1);
    ans += s15 * (s5-1);
    ans += s5*(s5-1)/2 * (s3-2);
    cout << ans << endl;
}