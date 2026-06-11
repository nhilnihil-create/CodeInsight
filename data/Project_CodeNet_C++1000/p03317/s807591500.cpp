#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int gcd(int a, int b)
{
	if (a%b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a%b));
	}
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> al(n);
	rep(i, n) {
		cin >> al[i];
	}
	int min = *min_element(al.begin(), al.end());
	int count = 0;
	int minc = 0;
	rep(i, n) {
		if (min != al[i])
		{
			count++;
		}
	}
	int ans = count / (k - 1);
	if (count % (k - 1) != 0) {
		ans++;
	}
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}

