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
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
//max_element


int N, M;
vector<int> S[11];
int P[11];

signed main()
{
	cin >> N >> M;
	REP(i, M)
	{
		int k;
		cin >> k;
		REP(j, k)
		{
			int s;
			cin >> s;
			S[i].push_back(s);
		}
	}
	REP(i, M)
	{
		cin >> P[i];
	}

	int ans = 0;
	int max = (1LL << N) - 1;
	for (int i = 0; i <= max; i++)
	{
		bool full = true;
		for (int j = 0; j < M; j++)
		{
			int cur = 0;
			for (int s : S[j])
			{
				if ((i & (1LL << (s - 1))) > 0)
				{
					cur ^= 1;
				}
			}
			if (cur != P[j])
			{
				full = false;
			}
		}
		if (full)
		{
			ans++;
		}
	}

	cout << ans << endl;
}

