#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1'000'000'009;

// 素数判定:O(sqrt(N))
const bool IsPrime(const LLONG N)
{
    if (N == 1) return false;
    for (LLONG d = 2; d * d <= N; ++d)
    {
        if (N % d == 0) return false;
    }
    return true;
}

int main()
{
	// Nが「2017に近い数」かどうかはO(log(N))でチェックできる
	// N <= 1e5 より，「2017に近い数」のリストを O(NlogN) で計算しておく

	int imos[100'000];
	imos[0] = 0;
	int sum = 0;
	for (int N = 1; N <= 100'001; N += 2)
	{
		if (IsPrime(N) && IsPrime((N + 1) / 2))
		{
			++sum;
		}
		imos[N / 2 + 1] = sum;
	}

	int Q; cin >> Q;
	REP(i, Q)
	{
		int li, ri; cin >> li >> ri;
		cout << imos[ri / 2 + 1] - imos[li / 2 - 1 + 1] << endl;
	}
}
