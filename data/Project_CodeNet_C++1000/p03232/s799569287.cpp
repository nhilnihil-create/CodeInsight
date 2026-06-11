#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define eps 0.000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*2
#define REP(i,n) for(long long i = 0;i < n;++i)
long long gekoa[200000] = {};
long long gyaku(long long n){
	if(gekoa[n]) return gekoa[n];
	long long ans = 1;
	long long now = n;
	long long hoge = n;
	long long geko = MAX_MOD-2;
	while(geko != 0){
		if(geko % 2 == 1){
			ans *= now;
			ans %= MAX_MOD;
		}
		now *= now;
		now %= MAX_MOD;
		geko /= 2;
	}
	return gekoa[hoge] = ans;
}
int main(){
	int n;
	cin >> n;
	long long nya = 1;
	REP(i,n){
		nya *= (long long)(i+1);
		nya %= MAX_MOD;
	}
	REP(i,n){
		gyaku(i+1);
		gekoa[i+1] *= nya;
		gekoa[i+1] %= MAX_MOD;
		gekoa[i+1] += gekoa[i];
		gekoa[i+1] %= MAX_MOD;
	}
	long long ans = 0;
	REP(i,n){
		long long nya;
		cin >> nya;
		long long bobo = gekoa[n-i] + gekoa[i+1] - gekoa[1];
		bobo %= MAX_MOD;
		ans += nya * bobo;
		ans %= MAX_MOD;
		if(ans < 0){
			ans += -ans * MAX_MOD + MAX_MOD;
			ans %= MAX_MOD;
		}
	}
	cout << ans << endl;
	return 0;
}