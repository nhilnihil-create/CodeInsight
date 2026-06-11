/*  /$$                                     /$$
      | $$                                    | $$
  /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$
 /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$  | $$| $$$$$$$$| $$      | $$  \ $$| $$  | $$| $$$$$$$$| $$  \__/
| $$  | $$| $$_____/| $$      | $$  | $$| $$  | $$| $$_____/| $$
|  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$$| $$
 \_______/ \_______/ \_______/ \______/  \_______/ \_______/|__//$$$$$$ /$$$$$$
                                                               |______/|______/

*/
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <unordered_map>
#define fastio        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ln            cout << endl;
#define vi            vector<int>
#define vll           vector<long long>
#define sortl(vec)    sort(vec.begin(), vec.end());
#define sortr(vec)    sort(vec.rbegin(), vec.rend());
#define forn(i, x, n) for(long long i = x; i < n; i++)
#define revn(i, n, x) for(long long i = n; i >= x; i--)
#define in(vec)       for(auto &it : vec) cin >> it;
#define	out(vec)      for(auto &it : vec) cout << it << " "; ln
#define ll            long long
#define pb            emplace_back
#define mp            make_pair
#define um            unordered_map
#define pii           pair<int, int>
#define pll           pair<ll, ll>
#define f             first
#define sec           second
#define pi            3.14159265359
#define o(x)		  cout << x << endl;
#define CLOCK         cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
using namespace std;

const ll NN = 200005;
const ll mod = 1000000007;
//https://codeforces.com/blog/entry/74640?#comment-587521

ll bS(ll l, ll r, ll x, vll arr) {
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}

void primeFactors(ll n) {
	while (n % 2 == 0) {
		//cout << 2 << " ";
		n = n / 2;
	}

	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			//cout << i << " ";
			n = n / i;
		}
	}

	if (n > 2)
		cout << n << " ";
}

ll power(ll x, ll y, ll p) {
	ll res = 1;
	x = x % p;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modulo(ll a, ll b) {
	ll c = a % b;
	return (c < 0) ? c + b : c;
}

//Use these functions below only when modulus is involved
ll mul(ll x, ll y) {
	return (x * y) % mod;
}

ll inv(ll x) {
	return power(x, mod - 2, mod);
}

ll divide(ll x, ll y)
{
	return mul(x, inv(y));
}

ll fact[NN];
void precalc() { // Call this once in main()
	fact[0] = 1;
	for (ll i = 1; i < NN; i++)
		fact[i] = mul(fact[i - 1], i);
}

ll nCr(ll n, ll k) {
	return divide(fact[n], mul(fact[k], fact[n - k]));
}

int main() {
// in(vec) works for size-defined type vectors

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	fastio
	ll t = 1;
	while (t--) {
		ll n;
		cin >> n;
		map<ll, ll>hash;
		vll vec(n + 1);
		forn(i, 1, n + 1)
		cin >> vec[i];
		forn(i, 1, n + 1) {
			vec[i] = vec[i] - i;
			hash[vec[i]]++;
		}
		ll ind = 0, sum = 0;
		if (n & 1)
			ind = (n + 1) / 2;

		else
			ind = n / 2;
		for (auto i : hash) {
			if (sum + i.sec < ind) {
				sum += i.sec;
				continue;
			}
			else {
				ind = i.f;
				break;
			}

		}
		ll ans = 0;
		forn(i, 1, n + 1) {
			ans += abs(vec[i] - ind);

		}
		o(ans)

	}
	CLOCK
	return 0;
}

