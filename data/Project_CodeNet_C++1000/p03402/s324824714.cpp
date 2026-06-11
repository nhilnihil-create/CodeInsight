#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

using namespace std;

class D {
	int a, b;
public:
	D()
	{
		cin >> a >> b;
	}
	void solve()
	{

		vector<string> ans(100);
		string whiterow(100, '.');
		string brackrow(100, '#');
		REP(i, 50)
		{
			ans[i] = whiterow;
			ans[100 - i - 1] = brackrow;
		}
		
		a--; b--;

		while (a)
		{
			for (int row{ 99 }; row >= 50 && a; row-=2)
			{
				//if (row & 1)
				//{
				for (int col{ 0 }; col < 100 && a; col += 2)
				{
					ans[row][col] = '.';
					a--;
				}
				//}
				//else
				//{
				//	for (int col{ 1 }; col < 100 && a; col += 2)
				//	{
				//		ans[row][col] = '.';
				//		a--;
				//	}
				//}
			}
		}
		while (b)
		{
			for (int row{ 0 }; row < 50 && b; row+= 2)
			{
				//if (row & 1)
				//{
				for (int col{ 0 }; col < 100 && b; col += 2)
				{
					ans[row][col] = '#';
					b--;
				}
				//}
				//else
				//{
				//	for (int col{ 1 }; col < 100 && b; col += 2)
				//	{
				//		ans[row][col] = '#';
				//		b--;
				//	}
				//}
			}
		}

		cout << "100 100" << endl;
		REP(i, 100)
			cout << ans[i] << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}