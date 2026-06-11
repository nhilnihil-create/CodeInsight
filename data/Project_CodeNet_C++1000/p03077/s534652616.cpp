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
	ll N;
	vector<ll> A(5);

	cin >> N;
	ll min_ = numeric_limits<ll>::max();
	int min_i;
	rep(i, 5)
	{
		cin >> A[i];
		if (min_ > A[i])
		{
			min_ = A[i];
			min_i = i;
		}
	}

	cout << 4 + divide_ceil(N, min_) << endl;
	
}