#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1LL << 60
#define MAX 1000000000
int main(void) {
	int N, M;
	ll ans = 0, c = 0;
	scanf("%d%d", &N, &M);
	vector<ll> A(N), S(N + 1);
	map<ll, ll> R;
	rep(i, 0, N)scanf("%lld", &A[i]);
	S[0] = 0;
	rep(i, 1, N + 1)S[i] = S[i - 1] + A[i - 1];
	rep(i, 0, N + 1)R[S[i] % M]++;
	for (auto c : R)ans += c.second * (c.second - 1) / 2;
	printf("%lld", ans);
	return 0;
}