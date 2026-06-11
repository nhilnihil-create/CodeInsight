#include "bits/stdc++.h"
using namespace std;
using ll = long long;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

long long S(long long n) {
	long long ret = 0;
	while (n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

ll mypow(ll b, ll n) {
	return n == 0 ? 1 : b * mypow(b, n - 1);
}

long long snuke(long long n) {
	//priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>>val;
	GPQ<pair<double, ll>> val;
	long long dig = 0;
	while (mypow(10,dig)<=n) {
		for (long long i = 1;i<=9;++i) {//★★
			long long v = n - n % (mypow(10, dig + 1)) + i * mypow(10, dig) - 1;
			if (v >= n) {
				val.push(make_pair(v * 1.0 / S(v), v));
			}
		}
		++dig;
	}
	--dig;    
	
	// 1桁もnと一致しないものを列挙
	for (ll i = 1; i <= 100; ++i) {
		ll v = i * mypow(10, dig) - 1;
		if (v >= n) {
			val.push(make_pair(v * 1.0 / S(v), v));
		}
	}

	auto ret = val.top();
	// g(m)とmが最小となる(g(m), m)の組

	return ret.second;
}


int main() {
	long long K;
	cin >> K;
	long long pre = 1;
	for (long long i = 0;i<K;++i) {
		cout << pre <<endl;
		pre = snuke(pre+1);
	}
	return 0;
}
