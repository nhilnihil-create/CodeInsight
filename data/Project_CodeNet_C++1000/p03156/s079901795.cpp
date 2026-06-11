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
	int n, a, b; cin >> n >> a >> b;
	int x, y, z; x = y = z = 0;
	while (n--)
	{
		int p; cin >> p;
		if (p <= a)++x;
		else if (b < p)++z;
		else ++y;
	}
	cout << min({ x,y,z }) << endl;
}