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
#include <deque>
#include <bitset>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) v.erase(remove(v.begin(), v.end(), a), v.end())
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPE(i, n) for (int (i) = 0; (i) <= (n); (i)++)
using namespace std;

int N, A, B;

signed main()
{
	cin >> N >> A >> B;

	if (N < A || N < B)
	{
		cout << "-1" << endl;
		return 0;
	}
	if (A == 1)
	{
		if (B == N)
		{
			REP(i, N) cout << (i ? " " : "") << (N - i);
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
		return 0;
	}
	if (B == 1)
	{
		if (A == N)
		{
			REP(i, N) cout << (i ? " " : "") << (i + 1);
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
		return 0;
	}

	int need = A + B - 1;

	if (need > N)
	{
		cout << -1 << endl;
		return 0;
	}

	int crap = N - need;

	if (ceil(crap / (double)(A - 1)) <= B - 1)
	{
		for (int i = 0; i < crap; i++)
		{
			int t = i / (A - 1);
			int a = i % (A - 1);
			if (crap < (A - 1) * (t + 1))
			{
				int b = ((A - 1) * t);
				int n = A + i - b;
				cout << (i ? " " : "") << (n + 1);
			}
			else
			{
				int n = (N - (B - 1)) - ((A - 1) * t) - ((A - 1) - a);
				cout << (i ? " " : "") << (n + 1);
			}
		}
	}
	else if (ceil(crap / (double)(B - 1)) <= A - 1)
	{
		for (int i = 0; i < crap; i++)
		{
			int t = i / (B - 1);
			int a = i % (B - 1);
			if (crap < (A - 1) * (t + 1))
			{
				int r = crap - i;
				int n = (N - B) - r;
				cout << (i ? " " : "") << n;

			}
			else
			{
				int n = (A + 1) + ((B - 1) * t) + a;
				cout << (i ? " " : "") << n;
			}
		}
	}
	else
	{
		cout << "-1" << endl;
		return 0;
	}
	
	for (int i = 0; i < B - 1; i++)
	{
		cout << " " << (N - i);
	}

	for (int i = 0; i < A; i++)
	{
		cout << " " << (i + 1);
	}
}