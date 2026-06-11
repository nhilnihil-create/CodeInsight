#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vs = vector<string>;
using Vb = vector<bool>;
using the = pair<int, int>;

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int main() {
	string a, b;
	cin >> a >> b;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	//cout << a << b << endl;
	if (a < b)  cout << "Yes" << endl;
	else  cout << "No" << endl;
}
