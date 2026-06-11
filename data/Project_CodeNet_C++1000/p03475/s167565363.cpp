#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
int main() {
	int N;
	cin >> N;
	vector<int> C(N), F(N), S(N), T(N);
	rep(i, 0, N - 1)cin >> C[i] >> S[i] >> F[i];
	rep(i, 0, N - 1) {
		int p = i;
		T[i] = S[i] + C[i];
		while (++p != N - 1) {
			if (S[p] <= T[i]) {
				T[i] = ((T[i] - 1) / F[p] + 1) * F[p];
				T[i] += C[p];
			}
			else T[i] = S[p] + C[p];
		}
	}
	rep(i, 0, N) {
		printf("%d\n", T[i]);
	}
	return 0;
}
