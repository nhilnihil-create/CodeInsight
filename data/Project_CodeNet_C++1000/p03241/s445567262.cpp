//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,M;

LL ans = 0;

vector<LL> calc_divisor(LL x){
	vector<LL> ret;
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			ret.push_back(i);
			if(i!=x/i)ret.push_back(x/i);
		}
	}
	sort(ret.begin(),ret.end(),greater<LL>());
	return ret;
}

void solve(){
	vector<LL> divisor = calc_divisor(M);
	for(int i=0;i<divisor.size();i++){
		if(M/N>=divisor[i]){
			ans = divisor[i];
			return;
		}
	}
}
 
int main(){
    cin >> N >> M;

    solve();

	cout << ans << endl;
    return 0;
}