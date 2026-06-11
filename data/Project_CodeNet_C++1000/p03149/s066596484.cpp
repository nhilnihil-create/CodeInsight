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


int main()
{
	vector<int> a(4);
	rep(i, 4)cin >> a[i];
	sort(all(a));
	if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9)cout << "YES" << endl;
	else cout << "NO" << endl;
}