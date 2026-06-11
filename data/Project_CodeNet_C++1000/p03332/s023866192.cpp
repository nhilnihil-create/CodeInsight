////////////////////////////////////////////
///                                      ///
///        Template ver. 1.2. rapel      ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define F first
#define S second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const ll MOD = 998244353;
const int N = 3e5;

ll fct[N + 5], inv[N + 5];

ll fast(ll A, ll B) {
	ll res = 1;
	while(B) {
		if(B & 1) res = res * A % MOD;
		B /= 2;
		A = A * A  % MOD;
	}
	return res;
}

void pre() {
	fct[0] = 1;
	for(int i = 1;i <= N;i++) fct[i] = fct[i - 1] * i % MOD;
	inv[N] = fast(fct[N], MOD - 2);
	for(int i = N - 1;i >= 0;i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

ll combin(int n, int r) {
	if(n < r) return 0;
	return fct[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void hora(int tc) {
	ll n, a, b, k;
	cin>>n>>a>>b>>k;
	ll total = 0;
	for(int i = 0;i <= n;i++) {
		ll sisak = k - i * a;
		if(sisak % b) continue;
		if(sisak < 0) continue;
		ll ada = sisak / b;
		if(ada > n) continue;
		total = (total + combin(n, i) * combin(n, ada)) % MOD;
	}
	cout<<total<<endl;
}

int main(){
	pre();
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
