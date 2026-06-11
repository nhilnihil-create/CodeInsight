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
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main() {
	int N, s, e, r;
	cin >> N;
	vector<int> A(N), B(N), D(N);
	rep(i, 0, N)cin >> A[i];
	rep(i, 0, N)cin >> B[i];
	rep(i, 0, N) {
		D[i] = A[i] - B[i];
	}
	sort(all(D));
	e = N - 1, s = 0;
	r = 0;
	while (D[s] < 0) {
		if (D[e] <= 0) {
			puts("-1");
			return 0;
		}
		r += D[e];
		e--;
		//printf("r:%d\n", r);
		while (D[s] < 0 && r + D[s] > 0) {
			//printf("r:%d\n", r);
			r += D[s];
			s++;
		}
	}
	printf("%d\n", N - e - 1 + s);
	return 0;
}
