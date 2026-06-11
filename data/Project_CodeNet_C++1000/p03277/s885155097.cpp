#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>

//LLONG_MAX
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
using namespace std;


int N;
int a[100001];
int b[100001];
int c[100001];
int s[100001];
int w[100001];
int all;
int tbl[1000000] = {};

int tento_cnt;

void tento_sub(int l, int m, int r)
{
	if (r - l <= 1) return;

	tento_sub(l, l + (m - l) / 2, m);
	tento_sub(m, m + (r - m) / 2, r);

	int l_index = l;
	int r_index = m;

	int index = l;
	while (l_index < m || r_index < r)
	{
		if (l_index == m)
		{
			w[index++] = s[r_index++];
		}
		else if (r_index == r)
		{
			w[index++] = s[l_index++];
		}
		else if (s[l_index] <= s[r_index])
		{
			w[index++] = s[l_index++];
		}
		else if (s[l_index] > s[r_index])
		{
			tento_cnt += (m - l_index);
			w[index++] = s[r_index++];
		}
		
		
	}

	memcpy(s + l, w + l, sizeof(int) * (r - l));
}

void tento()
{
	tento_cnt = 0;
	tento_sub(0, (N + 1) / 2, N + 1);
}

bool isOK(int index)
{
	//int n = c[index];
	int n = index;

	for (int i = 0; i < N; i++)
	{
		b[i] = (a[i] < n) ? -1 : 1;
	}
	s[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		s[i] = s[i - 1] + b[i - 1];
	}

	tento();
	int t = tento_cnt;

	int pat = (all - t);
	if (pat * 2 >= all)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int binary_search()
{
	int left = -1;
	int right = 1000000001;
	while (right - left > 1)
	{
		int mid = left + (right - left) / 2;
		if (isOK(mid))
			right = mid;
		else
			left = mid;
	}
	return left;
}

signed main()
{
	cin >> N;
	REP(i, N) cin >> a[i];

	memcpy(c, a, sizeof(a));
	ARY_SORT(c, N);

	all = ((N + 1) * N) / 2;

	int ans = binary_search();

	//ans = MAX(0, MIN(N - 1, ans));
	//cout << c[ans] << endl;

	cout << ans << endl;

	//N = 5;
	//s[0] = 3;
	//s[1] = 1;
	//s[2] = 7;
	//s[3] = 9;
	//s[4] = 5;

	//tento();
	//cout << tento_cnt << endl;

	return 0;
}






