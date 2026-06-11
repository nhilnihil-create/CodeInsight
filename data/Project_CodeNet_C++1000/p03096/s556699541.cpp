//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc031/tasks/agc031_b

//参考：
//https://www.hamayanhamayan.com/entry/2019/03/17/003754

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
LL C[200000];

LL ans = 0;

void solve(){
	//dp[i]:i番目の石まで塗り替えが終わっている場合の組合せ
	vector<LL> dp(N+1,0);
	dp[0] = 1;
	//(1)i+1番目の石には何もしない
	//(2)i+1番目以前の石で色がcのものと組合せて塗り替える
	//という選択が考えられる。
	//前者の操作は普通にdp[i + 1] += dp[i]である。

	//今までに何回色iが出てきたかをsm[i]とする
	vector<LL> sm(200001,0);
	for(int i=0;i<N;i++){
		if(i>=1){
			if(C[i]==C[i-1]){
				dp[i+1] = dp[i];
				continue;
			}
		}
		dp[i+1] = (dp[i] + sm[C[i]])%mod;
		sm[C[i]] = (sm[C[i]] + dp[i])%mod;
	}
	ans = dp[N];
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> C[i];
 
    solve();

    cout << ans << endl;
    return 0;
}