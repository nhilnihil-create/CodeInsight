#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>
using namespace std;
int		cnt;

int		main(void)
{
	int		A, B;
	cin >> A >> B;
	cout << (B % A == 0 ? A + B : B - A) << endl;
}
