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
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

template<typename T>
constexpr T gcd(T a, T b)
{
	if (a < b) swap(a, b);

	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main()
{
	int N;
	ll X;
	cin >> N >> X;

	vector<ll> x(N);
	rep(i, N)
	{
		cin >> x[i];
		x[i] = abs(x[i] - X);
	}

	ll D = x[0];
	rep(i, N-1)
	{
		D = gcd(D, x[i+1]);
	}

	cout << D << endl;
	
	return 0;
}