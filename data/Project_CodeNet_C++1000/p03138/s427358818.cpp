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
using namespace std;
 
#define LL unsigned long long int
 
LL N,K;
LL A[200000];
 
LL ans;

LL f(LL X){
	LL ans = 0;
	for(int i=0;i<N;i++){
		ans+=(X^A[i]);
	}
	return ans;
}
 
void solve(){
	vector<int> bit_counter(64,0);
	//A[0]~A[N-1]のうち、
	//下から数えてibit目に1が出てきた回数をbit_counter[i]とおく
	for(int i=0;i<64;i++){
		for(int k=0;k<N;k++){
			int bit = (A[k]>>i)&1ll;
			bit_counter[i] += bit;
		}
	}
	for(int i=63;i>=0;i--){
		if(ans+(1ll<<i)<=K){
			if(bit_counter[i]<(N+N%2)/2) ans += (1ll<<i);
		}
	}
	ans = f(ans);
}
 
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++) cin >> A[i];
 
	solve();

	cout << ans << endl;
	return 0;
}