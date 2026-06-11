#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
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
#include <random>
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
#define REPE(i, n) for (int (i)=0; (i) <= (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
//void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void Yes() { cout << "Yes" << endl; } 
void No() { cout << "No" << endl; }

signed main()
{
	int N, A, B;
	cin >> N >> A >> B;

	int ans = 0;
	for (int i = 0; i <= N; i++)
	{
		int sum = 0;
		int n = i;
		while (n > 0)
		{
			int s = n % 10;
			sum += s;
			n /= 10;
		}
		if (A <= sum && sum <= B)
		{
			ans += i;
		}
	}
	cout << ans << endl;
}


