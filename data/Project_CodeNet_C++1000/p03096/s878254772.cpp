////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
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
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 2e5;
const LL MOD = 1e9 + 7;
vector<int> lst;
LL dp[N + 5];
LL pref[N + 5];
LL psum[N + 5];

void hora(int tc) {
	int n;
	cin>>n;
	lst.PB(0);
	for(int i = 0;i < n;i++) {
		int x;
		cin>>x;
		if(lst.back() == x) continue;
		lst.PB(x);
	}
	dp[0] = pref[0] = 1;
	psum[lst[1]] = 1;
	n = lst.size();
	n--;
	for(int i = 1;i <= n;i++) {
		dp[i] = (dp[i] + psum[lst[i]]) % MOD;
		psum[lst[i + 1]] = (psum[lst[i + 1]] + dp[i]) % MOD;
	}
	cout<<dp[n]<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


