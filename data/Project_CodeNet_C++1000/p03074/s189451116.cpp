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

const ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
const ll MOD = 1000000007;

template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } else return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }

int main() {
	int n, k;
	cin >> n >> k;

  string s; cin >> s;

	int r = 0, ans = 0, man = 0;
	while(s[r] == '1') r++;
	rep(l, n) {
	  while (r < l) r++;
		while ( r < n && man < k) {
		  if(r == n - 1 || s[r] == '1' && s[r + 1] == '0') man++;
			r++;
		}
		//cout << l << " " << r-1 << endl; 
		chmax(ans, r - l);
		while (l + 1 < n && !(s[l] == '0' && s[l + 1] == '1')) l++;
		man--;
	}
	cout << ans << endl;
}
