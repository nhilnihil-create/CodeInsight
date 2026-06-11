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
const int N = 2e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int t, d;
		cin >> t >> d;
		v[t].push_back(d);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(v[i].rbegin(), v[i].rend());
	}
	sort(v + 1, v + n + 1, [](vector<int>& v1, vector<int>& v2)->bool
		{
			if (v1.empty()) return false;
			if (v2.empty()) return true;
			return v1[0] > v2[0];
		});
	priority_queue<int, vector<int>, greater<int>> pq;
	LL tot = 0;
	LL ans = 0;
	LL sum = 0;
	for (int i = 1; i <= k; i++)
	{
		if (v[i].empty()) break;
		sum += v[i][0];
		for (int j = 1; j < v[i].size(); j++)
		{
			pq.push(v[i][j]);
			sum += v[i][j];
		}
		while (pq.size() + i > k)
		{
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans, sum + 1LL * i * i);
	}
	cout << ans << endl;
	return 0;
}