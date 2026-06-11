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

double Snuke(int n)
{
	int a = n;
	int b = 0;
	while (n > 0)
	{
		b += n % 10;
		n /= 10;
	}
	return a / (double)b;
}

signed main()
{
	int K;
	cin >> K;

	int a = 0;
	int nine = 0;
	int k = 1;
	for (int i = 0; i < K; i++)
	{
		while (true)
		{
			a++;
			if (a == 1000)
			{
				a = 100;
				nine = (nine * 10) + 9;
				k *= 10;
			}
			int s = a * k + nine;

			bool flg = false;
			double sn = Snuke(s);
			for (int j = a + 1; j < 1000; j++)
			{
				int ss = j * k + nine;
				if (sn > Snuke(ss))
				{
					flg = true;
					break;
				}
			}
			if (!flg)
			{
				cout << s << endl;
				break;
			}
		}
	}
}


//double S(int n)
//{
//	int a = n;
//	int b = 0;
//	while (n > 0)
//	{
//		b += n % 10;
//		n /= 10;
//	}
//	return a / (double)b;
//}
//
//signed main()
//{
//	for (int i = 1; i < 1000000; i++)
//	{
//		double s1 = S(i);
//
//		bool flg = false;
//		for (int j = i + 1; j < 1000000; j++)
//		{
//			double s2 = S(j);
//			if (s1 > s2)
//			{
//				flg = true;
//				break;
//			}
//		}
//		if (!flg)
//		{
//			cout << i << endl;
//		}
//	}
//}
