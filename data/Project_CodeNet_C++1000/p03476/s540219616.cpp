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

bool is_prime[100001];
int like_num[100002];//2～nで条件に当てはまるものの個数
int eratosthenes(int n)
{
	int ret = 0;
	FOR(i, 2, n+1) {
		if (is_prime[i]) {
			ret++;
			for (int j = 2 * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return ret;
}

signed main(void) {
	rep(i, 100000) {
		is_prime[i] = true;
	}
	is_prime[0] = false;
	is_prime[1] = false;
	eratosthenes(100000);
	like_num[0] = 0;
	like_num[1] = 0;
	like_num[2] = 0;
	for (int i = 3; i <= 100000;i+=2) {
		if (is_prime[i] && is_prime[(i + 1) / 2]) {
			like_num[i] = like_num[i - 2] + 1;
		}
		else {
			like_num[i] = like_num[i - 2];
		}
	}
	int q;
	cin >> q;
	vector<int>l(q);
	vector<int>r(q);
	rep(i, q) {
		cin >> l[i] >> r[i];
	}
	rep(i, q) {
		println(like_num[r[i]] - like_num[l[i] - 2]);
	}
}