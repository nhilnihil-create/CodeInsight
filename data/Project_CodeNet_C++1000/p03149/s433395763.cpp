#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;

int main()
{
	vector<int> n(4);
	rep(i, 4)cin >> n[i];
	sort(ALL(n));
	if (n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9)co("YES");
	else co("NO");
	return 0;
}
