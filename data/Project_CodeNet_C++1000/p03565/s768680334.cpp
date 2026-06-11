#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	string ss, tt;
	bool flag;
	cin >> ss >> tt;
	int64 lens = ss.length(), lent = tt.length();
	for(int64 ii = 0;ii < lens - lent;ii++)
	{
		if(ss.substr(ii, lent) == tt)
		{
			for(int64 jj = 0;jj < lens;jj++)
			{
				if(ss[jj] == '?')
				{
					ss[jj] = 'a';
				}
			}
			cout << ss << endl;
			return 0;
		}
	}
	for(int64 ii = lens - lent;ii >= 0;ii--)
	{
		flag = false;
		for(int64 jj = 0;jj < lent;jj++)
		{
			if(ss[ii + jj] == tt[jj] || ss[ii + jj] == '?')
			{
				continue;
			}
			else
			{
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			for(int64 jj = 0;jj < lent;jj++)
			{
				ss[ii + jj] = tt[jj];
			}
			for(int64 jj = 0;jj < lens;jj++)
			{
				if(ss[jj] == '?')
				{
					ss[jj] = 'a';
				}
			}
			cout << ss << endl;
			return 0;
		}
	}
	cout << "UNRESTORABLE" << endl;
	return 0;
}