#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, A[1 << 18];
pair<int, int> zeta[1 << 18];

pair<int, int> update_best(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first < b.first) return update_best(b, a);
	return make_pair(a.first, max(a.second, b.first));
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < (1 << N); ++i) scanf("%d", A + i);

	for (int i = 0; i < (1 << N); ++i) zeta[i] = make_pair(A[i], 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < (1 << N); ++j) {
			int k = j | (1 << i);
			if (k != j) zeta[k] = update_best(zeta[j], zeta[k]);
		}
	}

	int ret = 0;
	for (int i = 1; i < (1 << N); ++i) {
		ret = max(ret, zeta[i].first + zeta[i].second);
		printf("%d\n", ret);
	}

	return 0;
}
