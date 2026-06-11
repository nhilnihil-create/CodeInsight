#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#include <map>	
#include <cmath>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define Cout(s) cout<<s<<endl
using namespace std;
typedef long long ll;
string Yes(bool b) { if (b) { return "Yes"; } else { return "No"; } }
string YES(bool b) { if (b) { return "YES"; } else { return "NO"; } }
//================================================

bool judge(ll x)
{
	string y = to_string(x);
	bool z = true;
	rep(i, sz(y) - 1)
	{
		if (abs(y[i] - y[i + 1]) > 1)
		{
			z = false; break;
		}
	}
	return z;
}

int a = 0, b = 0, c, d, n, k = 0, ans = 0;
string s, t;

int main()
{
	ll a, b, k, ans = 0, flag = 1,coin=0; cin >> k >> a >> b;
	if (b - a <= 2 || k - a + 1 < 2)
		ans = k + 1;
	else
	{
		flag = (k - a + 1) / 2;
		ans = a + (b - a) * flag + (k - a + 1) % 2;
	}
		
	cout << ans << endl;

	return 0;
}
