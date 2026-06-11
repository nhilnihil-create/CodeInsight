#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}
///////////////////////////

ll beki(ll n) {
	if (n == 0) { return 1;}
	return 10 * beki(n - 1);
}



int main() {

	ll X, Y;
	cin >> X >> Y;
	cout << X + Y / 2;
	
	system("PAUSE");
}