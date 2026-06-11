#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
using namespace std;
long long gcd(long long a, long long b) {
	if (a < b) gcd(b, a);
	long long  r;
	while ((r = a%b)) {
		a = b;
		b = r;
	}
	return b;
}
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t*b; swap(a, b);
		u -= t*v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}
namespace NTT {
	const int MOD = 998244353;  // to be set appropriately
	const long long PR = 3;     // to be set appropriately

	void trans(vector<long long> &v, bool inv = false) {
		int n = (int)v.size();
		for (int i = 0, j = 1; j < n - 1; j++) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (i > j) swap(v[i], v[j]);
		}
		for (int t = 2; t <= n; t <<= 1) {
			long long bw = modpow(PR, (MOD - 1) / t, MOD);
			if (inv) bw = modinv(bw, MOD);
			for (int i = 0; i < n; i += t) {
				long long w = 1;
				for (int j = 0; j < t / 2; ++j) {
					int j1 = i + j, j2 = i + j + t / 2;
					long long c1 = v[j1], c2 = v[j2] * w % MOD;
					v[j1] = c1 + c2;
					v[j2] = c1 - c2 + MOD;
					while (v[j1] >= MOD) v[j1] -= MOD;
					while (v[j2] >= MOD) v[j2] -= MOD;
					w = w * bw % MOD;
				}
			}
		}
		if (inv) {
			long long inv_n = modinv(n, MOD);
			for (int i = 0; i < n; ++i) v[i] = v[i] * inv_n % MOD;
		}
	}

	// C is A*B
	vector<long long> mult(vector<long long> A, vector<long long> B) {
		int size_a = 1; while (size_a < A.size()) size_a <<= 1;
		int size_b = 1; while (size_b < B.size()) size_b <<= 1;
		int size_fft = max(size_a, size_b) << 1;

		vector<long long> cA(size_fft, 0), cB(size_fft, 0), cC(size_fft, 0);
		for (int i = 0; i < A.size(); ++i) cA[i] = A[i];
		for (int i = 0; i < B.size(); ++i) cB[i] = B[i];

		trans(cA); trans(cB);
		for (int i = 0; i < size_fft; ++i) cC[i] = cA[i] * cB[i] % MOD;
		trans(cC, true);

		vector<long long> res((int)A.size() + (int)B.size() - 1);
		for (int i = 0; i < res.size(); ++i) res[i] = cC[i];
		return res;
	}
};
vector<int>graph[100005];
int dotti[100005] = { 0 };
long long cnt[3] = { 0 };
long long n, m;
int judge = 0;
void dfs(int now, int ki) {
	cnt[ki] += 1;
	if (judge)return;
	for (int i = 0; i < graph[now].size(); i++) {
		if (dotti[graph[now][i]] == ki) {
			judge = 1; return;
		}
		if (dotti[graph[now][i]] == 0) {
			dotti[graph[now][i]] = (ki==1?2:1);
			dfs(graph[now][i], (ki==1?2:1));
		}
	}
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 3) {
		cout << "2 5 63"; return 0;
	}
	queue<int>que[7];
	for (int i = 8; i <= 30000; i+=6) {

		que[i % 6].push(i);
	}
	for (int i = 15; i <= 30000; i += 6) {

		que[i % 6].push(i);
	}
	for (int i = 10; i <= 30000; i += 6) {

		que[i % 6].push(i);
	}
	for (int i = 6; i <= 30000; i += 6) {

		que[i % 6].push(i);
	}
	vector<int>ans;
	n -= 4;
	ans.push_back(2);
	ans.push_back(3);
	ans.push_back(4);
	ans.push_back(9);
	while (n >= 2&&que[2].size()>0) {
		ans.push_back(que[2].front());
		ans.push_back(que[4].front());
		que[2].pop();
		que[4].pop();
		n -= 2;
	}
	while (n >= 2 && que[3].size()>1) {
		ans.push_back(que[3].front());
		que[3].pop();
		ans.push_back(que[3].front());
		que[3].pop();
		n -= 2;
	}
	while (n >= 1 && que[0].size()>0) {
		ans.push_back(que[0].front());
		que[0].pop();
		n -= 1;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}