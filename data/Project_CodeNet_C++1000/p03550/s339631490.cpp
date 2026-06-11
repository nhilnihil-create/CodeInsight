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
	int n, z, w; cin >> n >> z >> w;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	if (n == 1)cout << abs(a[0] - w) << endl;
	else cout << max(abs(a[n - 1] - w), abs(a[n - 1] - a[n - 2])) << endl;
}