#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
typedef long long ll;
using namespace std;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
//#define int long long

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	
	for (size_t i = 0; i < s.size()-8; i++)
	{
		cout << s[i];
	}
	cout << endl;

	return 0;
}
