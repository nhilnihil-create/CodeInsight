#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;

int main()
{
	ll x, y;
	cin >> x >> y;
	int count = 0;
	while (y >= x){
		count++;
		x *= 2;
	}
	cout << count << endl;
}
