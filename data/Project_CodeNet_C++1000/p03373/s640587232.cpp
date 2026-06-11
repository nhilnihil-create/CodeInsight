#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
using namespace std;

typedef long long ll;

#define INF 100000000;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define eps 1.0e-14;
#define mod 1e9 + 7;

int main(){
	int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
	ll ans[3] = {0,0,0};
	ll tans = 0;
	ans[0] = a * x + b * y;
	int min = (x >= y) ? y : x;
	int big = (x >= y) ? x : y;
	int bigab = (x >= y) ? a : b;
	int minab = (x >= y) ? b : a;
	ans[1] = c * (min * 2) + (big - min) * bigab;
	ans[2] = c * (big * 2);
	tans = (ans[0] >= ans[1]) ? ans[1] : ans[0];
	tans = (tans >= ans[2]) ? ans[2] : tans;
	cout << tans << endl;
	return 0;
}
