#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()
#define VEC(TYPE, A, NAME, INIT) vector<TYPE> NAME(A, INIT)
#define VEC2(TYPE, A, B, NAME, INIT) vector<vector<TYPE>> NAME(A, vector<TYPE>(B, (INIT)))

int main()
{
	ull n = 0;
	cin >> n;
	if( n == 3 )
	{
		cout << 2 << " " << 5 << " " << 63 << endl;
	}
	else if( n <= 10000 )
	{
		cout << 3 << " " << 9;
		n -= 2;
		// 15000
		ull nn = n - 1;
		ull i = 2;
		ull sum = 0;
		for( ull j = 0; j < nn; i += 2, ++j, --n )
		{
			cout << " " << i;
			sum += i;
			sum = sum % 30;
		}
		for( ; true; i += 2 )
		{
			if( ( sum + i ) % 30 == 0 )
			{
				cout << " " << i << endl;
				break;
			}
		}
	}
	else
	{
		// 2000
		cout << 5 << " " << 25;
		n -= 2;
		for( ull i = 55; i <= 30000; i += 30, n -= 2 )
		{
			cout << " " << i - 20 << " " << i;
		}
		// 5000
		for( ull i = 27; i <= 30000; i += 30, n -= 5 )
		{
			cout << " " << i - 24 << " " << i - 18
			<< " " << i - 12 << " " << i - 6
			<< " " << i;
		}
		// 15000
		ull nn = n - 1;
		ull i = 2;
		ull sum = 0;
		for( ull j = 0; j < nn; i += 2, ++j, --n )
		{
			cout << " " << i;
			sum += i;
			sum = sum % 30;
		}
		for( ; true; i += 2 )
		{
			if( ( sum + i ) % 30 == 0 )
			{
				cout << " " << i << endl;
				break;
			}
		}
	}
	
	return 0;
}