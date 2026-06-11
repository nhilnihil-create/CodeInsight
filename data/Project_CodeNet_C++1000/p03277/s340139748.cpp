#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include<iomanip> 
#include<cmath>  
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<map>
// #include<unordered_map>
#include<set>
// #include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl
#define ln() cout << endl
const ll MAX_10p5 = 100010;
const ll MAX_10p9 = 1000000010;
const ll MAX_10p18 = 1000000000000000010;
const ll MOD = 1000000007;
const ll m4x[4] = { 1,0,-1,0 };
const ll m4y[4] = { 0,1,0,-1 };
const ll m8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const ll m8y[8] = { 0,1,1,1,0,-1,-1,-1 };
const ll m9x[9] = { 1,1,0,-1,-1,-1,0,1,0 };
const ll m9y[9] = { 0,1,1,1,0,-1,-1,-1,0 };

struct edge {
	ll from, to, cost;
	bool operator<(const edge& right) const {
		return cost < right.cost;
	}
	bool operator>(const edge& right) const {
		return cost > right.cost;
	}
};

struct point {
	ll x, y, idx;
	bool operator<(const point& right) const {
		return x == right.x ? y < right.y : x < right.x;
	}
	bool operator>(const point& right) const {
		return x == right.x ? y > right.y : x > right.x;
	}
};

ll bisect_left(ll arr[], ll arr_size, ll key) {
	return distance(arr, lower_bound(arr, arr + arr_size, key));
}

ll bisect_left(vector<ll> vc, ll key) {
	return lower_bound(vc.begin(), vc.end(), key) - vc.begin();
}

ll pow_mod(ll a, ll x) {
	if (x == 0) return 1;
	if (x == 1) return a;
	ll ret = pow_mod(a, x / 2);
	if (x % 2 == 0) ret = (ret*ret) % MOD;
	else ret = (a * ((ret*ret) % MOD)) % MOD;
	return ret;
}

void build_mod_fact(ll arr[], ll n) {
	arr[0] = 1;
	repi(i, 1, n + 1) {
		arr[i] = (arr[i - 1] * i) % MOD;
	}
	return;
}

void build_mod_fact_inv(ll arr_fact[], ll arr_fact_inv[], ll n) {
	arr_fact_inv[n] = pow_mod(arr_fact[n], MOD - 2);
	repd(i, n - 1, -1) {
		arr_fact_inv[i] = (arr_fact_inv[i + 1] * (i + 1)) % MOD;
	}
	return;
}

ll comb_mod(ll n, ll r, ll arr_fact[], ll arr_fact_inv[]) {
	return (((arr_fact[n] * arr_fact_inv[n - r]) % MOD) * arr_fact_inv[r]) % MOD;
}


///////////////////////////////////////////////////////////////////////////////////////

ll N, M, a[MAX_10p5], sum[MAX_10p5];
ll L[MAX_10p5], R[MAX_10p5];

ll merge(ll A[], ll n, ll left, ll mid, ll right) {
	ll i, j, k;
	ll cnt = 0;
	ll n1 = mid - left;
	ll n2 = right - mid;
	repi(i, 0, n1) L[i] = A[left + i];
	repi(i, 0, n2) R[i] = A[mid + i];
	L[n1] = R[n2] = MAX_10p18;
	i = j = 0;
	repi(k, left, right) {
		if (L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
			cnt += n1 - i;
		}
	}
	return cnt;
}

ll merge_sort(ll A[], ll n, ll left, ll right) {
	ll mid;
	ll v1, v2, v3;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		v1 = merge_sort(A, n, left, mid);
		v2 = merge_sort(A, n, mid, right);
		v3 = merge(A, n, left, mid, right);
		return v1 + v2 + v3;
	}
	else return 0;
}

bool judge(ll x) {
	sum[0] = 0;
	repi(i, 0, N) {
		if (a[i] >= x) {
			sum[i + 1] = sum[i] + 1;
		}
		else {
			sum[i + 1] = sum[i] - 1;
		}
	}
	return M - merge_sort(sum, N + 1, 0, N + 1) >= (M + 1) / 2;
}

ll solv() {
	ll left = 1, right = MAX_10p9;
	ll next, prev = -1;
	while (true) {
		next = (left + right) / 2;
		if (next == prev) return next;
		if (judge(next)) left = next;
		else right = next;
		prev = next;
	}
}

int main() {
	cin >> N;
	M = (N*(N + 1)) / 2;
	repi(i, 0, N)
		cin >> a[i];
	cout << solv() << endl;
	return 0;
}
