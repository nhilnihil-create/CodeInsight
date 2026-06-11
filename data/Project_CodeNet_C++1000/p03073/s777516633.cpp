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

#define int64 long long
#define uint64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define coutfix(i) cout << fixed << setprecision(i)
using namespace std;

int main()
{
	string ss;
	cin >> ss;
	int64 aa = 0;
	for(int64 ii = 0;ii < ss.length();ii++)
	{
		if((ss[ii] - '0') == ii % 2)
		{
			aa++;
		}
	}
	cout << min(aa, (int64)ss.length() - aa) << endl;
}
