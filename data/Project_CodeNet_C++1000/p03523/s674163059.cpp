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

int dp[10][10];

string target="AKIHABARA";
string s;

int solve(int l,int r) {
	if(l == target.size() && r == s.size()) return 1;
	if(l == target.size()) return 0;
//	cout<<"CHECK "<<l<<" "<<r<<endl;
	int &res = dp[l][r];
	if(res != -1) return res;
	res = 0;
	if(target[l] == s[r]) res = max(res, solve(l + 1, r + 1));
	if(target[l] == 'A') res = max(res, solve(l + 1, r));
	return res;
}

void hora(int tc) {
	cin>>s;
	if(s.size() > target.size()) cout<<"NO"<<endl;
	else {
		memset(dp, -1, sizeof dp);
		int res = solve(0, 0);
		if(res == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


