#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, kk;
	cin >> nn >> kk;
	if(nn % kk == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << 1 << endl;
	}
	return 0;
}
