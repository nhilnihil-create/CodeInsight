#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <complex>
#include <iomanip>
#include <random>

using namespace std;

typedef long long ll;
#define int ll

const int M = 998244353;
#define msum(a, b) ((a) + (b) >= M ? (a) + (b) - M : (a) + (b))
#define msub(a, b) ((a) - (b) < 0 ? (a) - (b) + M : (a) - (b))
#define mmult(a, b) (((a) * (b)) % M)

typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mmin(a, b) a = min(a, (b))
#define mmax(a, b) a = max(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SZ(a) ((int)(a).size())
#define watch(x) cout << (#x) << " = " << (x) << endl;

const double PI = 2 * acos(0.0);
const int oo = 1e9 + 100;
const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";

#define N 200000




signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	

	int q; cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		if (abs(b - a) <= 1)
			cout << 2 * min(a, b) - 2 << endl;
		else
		{
			int c = (int)sqrt(a * b);
			if (c * c == a * b)
				c--;
			if (c*(c + 1) >= a * b)
				cout << 2 * c - 2;
			else
				cout << 2 * c - 1;
			cout << endl;
		}
	}




}
