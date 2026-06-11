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



signed main()
{
	int S;
	cin >> S;
	int a = S / 100;
	int b = S % 100;
	
	bool is_yymm = (0 <= a && a <= 99 && 1 <= b && b <= 12);;
	bool is_mmyy = (1 <= a && a <= 12 && 0 <= b && b <= 99);
	
	if (is_yymm && is_mmyy)
	{
		cout << "AMBIGUOUS" << endl;
	}
	else if (is_yymm)
	{
		cout << "YYMM" << endl;
	}
	else if (is_mmyy)
	{
		cout << "MMYY" << endl;
	}
	else
	{
		cout << "NA" << endl;
	}
}

