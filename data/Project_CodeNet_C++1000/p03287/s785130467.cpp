#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;
#define MAX_N (100010)

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int sum_prev = 0;
	map<int, int> mods;
	mods[0] = 1;
	for (int i = 0; i < N; i++) {
		int A;
		scanf("%d", &A);

		int sum = (A + sum_prev) % M;
		mods[sum]++;
		sum_prev = sum;
	}

	ll res = 0;
	for (auto iter = mods.begin(); iter != mods.end(); iter++)
		res += (ll)iter->second * (ll)(iter->second - 1) / 2LL;

	printf("%lld\n", res);

	return 0;
}
