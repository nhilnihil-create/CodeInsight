#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>
#include <queue>
#include <stack>

typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
#define rep_r(i,s,n)for(ll i = n;i>s;i--)
#define rep_re(i,s,n)for(ll i = n;i>=s;i--)
using namespace std;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;

ll N, K;
ll a[1111];
vector<ll> cand;

// 渡されたbitを含む部分列の個数をカウントする
ll countMask(ll a) {
	ll ret = 0;
	for (ll x : cand) {
		if ((x & a) == a) { // これ頭良い
			ret++;
		}
	}
	return ret;
}

int main() {
	// 入力
	cin >> N >> K;
	for (ll i = 0; i < N; i++) {
		cin >> a[i];
	}

	// 部分列全列挙
	for (ll i = 0; i < N; i++) {
		ll sum = 0;
		for (ll j = i; j < N; j++) {
			sum += a[j];
			cand.push_back(sum);
		}
	}

	sort(cand.begin(), cand.end());
	reverse(cand.begin(), cand.end());

	ll mask = 0; // これが答えになる。条件を満たすbitをここに付け加えてく
	for (ll i = 40; i >= 0; i--) {
		if (countMask(mask | (1LL << i)) >= K) {
			mask |= (1LL << i);
		}
	}

	cout << mask << endl;

	return 0;
}
