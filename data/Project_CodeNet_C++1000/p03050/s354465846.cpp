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

LL ans = 0;

void solve(){
	//Nをmで割った時、商とあまりが同じ
	//これは N = pm + p (1<=p<=m-1)
	//と言い換えられる
	//N = p(m+1) より
	//各pについて、
	//Nがpで割り切れて、かつ m = N/p - 1 が
	//(1<=p<=m-1)
	//を満たすならmをどんどん加算していく
	for(LL p=1;p*p<N;p++){
		if(N%p==0){
			LL m = N/p - 1;
			if(p<=m-1) ans += m;
		}
	}
}
 
int main(){
    cin >> N;
 
    solve();
 
    cout << ans << endl;
    return 0;
}