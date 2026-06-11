#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

vector<long long> enum_divisors(long long N) {
	vector<long long> res;
	for (long long i = 1; i * i <= N; ++i) {
		if (N % i == 0) {
			res.push_back(i);
			// 重複しないならば i の相方である N/i も push
			if (N / i != i) res.push_back(N / i);
		}
	}
	// 小さい順に並び替える
	sort(res.begin(), res.end());
	return res;
}

int main()
{
	int n;
	cin >> n;

	int ans = 0;
	rep(i, n + 1) {
		if (i % 2 == 0) continue;
		vector<ll> res = enum_divisors(i);
		if (res.size() == 8) {
			++ans;
		}
	}
	cout << ans << endl;
	system("pause");
}


