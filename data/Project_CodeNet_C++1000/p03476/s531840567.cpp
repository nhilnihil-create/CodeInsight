#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

signed main(void) {
	int q;
	cin >> q;
	vector<pair<int, int>>lr(q);
	rep(i, q) {
		int l,r;
		cin >> l >> r;
		lr[i] = make_pair(l, r);
	}

	vector<bool>is_prime(100002, true);
	vector<int>c(100001, 0);//0からiまでで2017に似た数の個数
	is_prime[0] = is_prime[1] = false;
	FOR(i, 2, 100002) {
		if (is_prime[i]) {
			for (int j = 2*i; j <= 100000; j += i) {
				is_prime[j] = false;
			}
		}
	}
	c[0] = c[1] = c[2] = 0;
	for(int i=3;i<=100000;i+=2){
		if (is_prime[i] && is_prime[(i + 1) / 2]) { 
			c[i]=c[i-2]+1;
		}
		else c[i] = c[i - 2];
	}
	rep(i, q) {
		if (lr[i].first == 1) {
			println(c[lr[i].second] - c[0]);
		}
		else {
			println(c[lr[i].second] - c[lr[i].first - 2]);
		}
	}
}