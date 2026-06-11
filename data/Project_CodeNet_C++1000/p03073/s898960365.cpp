#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

template<typename T>
constexpr T divide_ceil(T a, T b)
{
	T remainder = a % b;
	return remainder == 0 ? a / b : (a + (b - remainder)) / b;
}


int main()
{
	string S;
	cin >> S;

	int oddZ = 0;
	int evenZ = 0;

	rep(i, S.size())
	{
		if (S[i] == '0')
		{
			if (i % 2 == 0) ++evenZ;
			else ++oddZ;
		}
	}

	int ans = min(evenZ + (S.size() / 2 - oddZ), oddZ + (divide_ceil(S.size(), static_cast<size_t>(2)) - evenZ));

	cout << ans << endl;
}