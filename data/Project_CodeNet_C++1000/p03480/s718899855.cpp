#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	int L = 0, R = n;
	int l = 0, r = n;
	int ans = n / 2;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (L + mid >= R - mid)
		{
			r = mid - 1;
			continue;
		}
		int tot = count(str.begin() + L + mid, str.begin() + R - mid, '0');
		if (tot == 0 || tot == R - mid - L - mid) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << n - ans << endl;
	return 0;
}
