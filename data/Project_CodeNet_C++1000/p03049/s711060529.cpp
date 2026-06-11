#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	int a = 0, b = 0, ba = 0, res = 0;
	while (n--)
	{
		string s; cin >> s;
		int l = s.size();
		rep(i, l - 1)
		{
			if (s.substr(i, 2) == "AB")++res;
		}
		if (s[0] == 'B'&&s[l - 1] == 'A')++ba;
		else if (s[0] == 'B')++b;
		else if (s[l - 1] == 'A')++a;
	}
	if (ba > 0)
	{
		res += (ba - 1);
		res += min(a, b);
		if (a != 0 || b != 0)++res;
	}
	else res += min(a, b);
	cout << res << endl;
}