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
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }

vector<int> yakusu(int n)
{
	vector<int> v;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			v.push_back(i);
			if (i != n / i)
			{
				v.push_back(n / i);
			}
		}
	}
	sort(v.begin(), v.end());
	return v;
}

signed main()
{
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		int n = yakusu(i).size();
		if (n == 8 && i % 2 == 1)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
}

//int N;
//int X[200001];
//int Y[200001];
//char C[200001];
//
//set<int> s[400001];
//
//signed main()
//{
//	cin >> N;
//	REP(i, N) cin >> X[i] >> Y[i] >> C[i];
//
//	int mi = LLONG_MAX;
//
//	for (int i = 0; i < N; i++)
//	{
//		if (C[i] == 'D')
//		{
//			s[X[i]].insert(Y[i]);
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		if (C[i] == 'U')
//		{
//			auto it = s[X[i]].upper_bound(Y[i]);
//			if (it != s[X[i]].end())
//			{
//				int sub = *it - Y[i];
//				mi = min(mi, sub);
//			}
//		}
//	}
//
//	cout << mi << endl;
//}

