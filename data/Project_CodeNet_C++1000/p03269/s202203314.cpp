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

vector<int> num;

vector<pair<pair<int,int>,int> >result;

void hora(int tc) {
	int n;
	cin>>n;
	if(n == 2) {
		cout<<2<<" "<<2<<endl;
		cout<<1<<" "<<2<<" "<<0<<endl;
		cout<<1<<" "<<2<<" "<<1<<endl;
		return ;
	}
	int tmpn = n;
//	n--;
	int base = 1;
	while(n >= 2 * base) {
		num.pb(base);
		base *= 2;
	}
	int sz = num.size();
	for(int i = 0;i < sz;i++) {
		result.pb({{i + 1, i + 2}, 0});
		result.pb({{i + 1, i + 2}, (1<<(sz - 1 - i))});
	}
	int ujung = sz + 1;
	n = tmpn;
	int b = 1;
	while(__builtin_popcount(n) != 1) {
		if(n & b) {
			n ^= b;
			result.pb({{1, ujung}, tmpn & n});
		}
		b *= 2;
		ujung--;
	}
	cout<<sz + 1<<" "<<result.size()<<endl;
	for(auto x: result) cout<<x.F.F<<" "<<x.F.S<<" "<<x.S<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
