#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
//	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	vll a(n, 0);
	rep(i, n) cin >> a[i];
	ll ans = a[n-1];
	if(n == 1 && ans != 0) ans = -1;
	for(int i = n-2; i >= 0; i--) {
		if(a[i] > i) {
			ans = -1;
			break;
		}
		if(a[i] + 1 < a[i+1]) {
			ans = -1;
			break;
		}
		else if(a[i] + 1 == a[i+1]) {
			continue;
		}
		else {
			ans += a[i];
		}
	}
	cout << ans << endl;
}
