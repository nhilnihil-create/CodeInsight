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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n), t(n);
	for (auto &x : t)
	{
		cin >> x;
		x *= 2;
	}
	for (auto &x : v)
	{
		cin >> x;
		x *= 2;
	}
	MEM(a, 0x3f);
	int l = 0, r = 0;
	for(int i = 0; i < n; i++)
	{
		r += t[i];
		for (int j = l; j <= r; j++) a[j] = min(a[j], v[i]);
		l = r;
	}
	a[0] = 0, a[r] = 0;
	for (int i = 1; i < r; i++)
	{
		a[i] = min(a[i], a[i - 1] + 1);
	}
	for (int i = r - 1; i >= 0; i--)
	{
		a[i] = min(a[i], a[i + 1] + 1);
	}
	double ans = 0;
	for (int i = 1; i <= r; i++)
	{
		ans += (a[i] + a[i - 1]) / 2.0;
	}
	printf("%.15f\n", ans / 4.0);
	return 0;
}
