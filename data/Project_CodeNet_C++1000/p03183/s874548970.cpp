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

struct block{
	LL w,s,v;
};

vector<block> vec;

const int N = 1e3, S = 1e4;
LL dp[N + 5][2 * S + 5];

bool cmp(block &A, block &B) {
	return A.s + A.w > B.s + B.w;
}

int n;

LL calc(int idx, int s) {
	if(n == idx) return 0;
	LL &res = dp[idx][s];
	if(res != -1) return res;
	res = calc(idx + 1,s);
	if(s - vec[idx].w >= 0) res = max(res, calc(idx + 1, min(vec[idx].s, s - vec[idx].w)) + vec[idx].v);
	return res;
}

void hora(int tc) {
	cin>>n;
	for(int i = 0;i < n;i++) {
		block A;
		cin>>A.w>>A.s>>A.v;
		vec.PB(A);
	}
	sort(vec.begin(),vec.end(), cmp);
	memset(dp,-1,sizeof dp);
	cout<<calc(0, 2 * S + 1)<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}

