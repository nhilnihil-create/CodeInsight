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
#define all(a)        a.begin(), a.end()
#define CLOCK         cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
using namespace std;

const ll Nfact = 200005;
const ll mod = 1000000007;
const ll Nseive = 1000005;
//https://codeforces.com/blog/entry/74640?#comment-587521

vector<bool> is_prime(Nseive, true);
void seive() {
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= Nseive; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= Nseive; j += i)
				is_prime[j] = false;
		}
	}
}

ll bSearch(ll l, ll r, ll x, vll arr) {
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

ll fact[Nfact];
void precalc() { // Call this once in main()
	fact[0] = 1;
	for (ll i = 1; i < Nfact; i++)
		fact[i] = mul(fact[i - 1], i);
}

ll nCr(ll n, ll k) {
	if (n < k)
		return 0;
	return divide(fact[n], mul(fact[k], fact[n - k]));
}

ll ct = 0;
bool checker(ll x, ll n) {
	if (x > n)
		return 0;
	ll ld, count3 = 0, count5 = 0, count7 = 0;
	while (x != 0) {
		ld = x % 10;
		if (ld == 3)
			count3++;
		else if (ld == 5)
			count5++;
		else
			count7++;
		x /= 10;

	}
	if (count3 && count5 && count7) {
		ct++;
	}
	return 1;

}
void dfs(ll x, ll n) {
	if (checker(x, n)) {
		dfs(x * 10 + 3, n);
		dfs(x * 10 + 5, n);
		dfs(x * 10 + 7, n);
	}
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
		dfs(0, n);
		o(ct)
	}
	CLOCK
	return 0;
}
//Credits: https://atcoder.jp/contests/abc114/submissions/15325859
