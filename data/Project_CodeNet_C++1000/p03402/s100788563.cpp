#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iomanip>

using namespace std;

/********** TEMPLATE STARTS HERE ***********/

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define gcd __gcd 
#define digits(n) (int)(log10(n) + 1)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <long long> vl;
typedef vector <pll> vll;
typedef vector <pii> vii;

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;

template <typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template <typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

/********** TEMPLATE ENDS HERE ***********/

const int DIM = 100;

main() 
{
	IOS
	
	int a, b;
	cin >> a >> b;
	
	a--;
	b--;
 
	cout << DIM << ' ' << DIM << '\n';
	
	for(int h = 0; h < DIM / 2; h++) 
	{
		for(int w = 0; w < DIM; w++) 
		{
			if(a > 0 && h % 2 == 0 && w % 2 == 0) 
			{
				cout << '.';
				a--;
			} 
			else 
			{
				cout << '#';
			}
		}
	
		cout << '\n';
  }
  
	for(int w = 0; w < DIM; w++) 
		cout << '.';
	
	cout << '\n';

	for(int h = DIM / 2 + 1; h < DIM; h++) 
	{
		for(int w = 0; w < DIM; w++) 
		{
			if(b > 0 && h % 2 == 0 && w % 2 == 0) 
			{
				cout << '#';
				b--;
			} 
			else 
			{
				cout << '.';
			}
		}
		
		cout << '\n';
	}
}