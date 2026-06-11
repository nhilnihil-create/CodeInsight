#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
using namespace std;


ll llmin(ll x, ll y){
	if (x < y) return x;
	return y;
}

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}


int main(){
	ll n, z, w;
	cin >> n >> z >> w;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) cout << abs(a[0] - w) << endl;
	else cout << llmax(abs(a[n-1] - w), abs(a[n-2] - a[n-1])) << endl;
	return 0;
}
