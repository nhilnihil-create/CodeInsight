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

LL N;

string ans = "";

void solve(){
	if(N==0){ans = "0";return;}
	while(N!=0){
		ans = (char)(abs(N)%2 + '0') + ans;
		if(N<0){
			N = -(N-abs(N)%2)/2;
		}
		else if(N>0){
			N = -N/2;
		}
	}
}
 
int main(){
    cin >> N;
 
    solve();
 
    cout << ans << endl;
    return 0;
}