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
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	string s; cin >> s;
	vector<bool> alp(26, false);
	if (s.size() == 26)
	{
		string tmp = s;
		if (next_permutation(all(tmp)))
		{
			string res = "";
			rep(i, tmp.size())
			{
				res += tmp[i];
				if (tmp[i] != s[i])break;
			}
			cout << res << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	else
	{
		for (char x : s)alp[x - 'a'] = true;
		rep(i, 26)if (!alp[i])
		{
			s.push_back(i + 'a');
			break;
		}
		cout << s << endl;
	}
}