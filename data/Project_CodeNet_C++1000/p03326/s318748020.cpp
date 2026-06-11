//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc100/tasks/abc100_d
//ポイント：
//最終的な値がx>0ならできるだけxが大きくなるように集めた方がいい
//x<0ならできるだけ負の方向に大きくなるように集めた方がいい
//xだけでなくy,zも同様

//参考：https://babcs2035.hateblo.jp/entry/2018/06/17/124029

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
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,M;
LL x[1000],y[1000],z[1000];
 
LL ans = 0;

void solve(){
	//bitの1ビット目が1ならxを負の方向に伸ばすと仮定
	//bitの2ビット目が1ならyを負の方向に伸ばすと仮定
	//bitの3ビット目が1ならzを負の方向に伸ばすと仮定
	for(int bit=0;bit<(1<<4);bit++){
		LL x_sign = (bit&1)?-1:1;
		LL y_sign = ((bit>>1)&1)?-1:1;
		LL z_sign = ((bit>>2)&1)?-1:1;

		//各ケーキごとにx+y+zを計算,priority_queueに入れて
		//x+y+zのでかいものからM個取り出す
		priority_queue<LL> pq;
		for(int i=0;i<N;i++){
			pq.push(x_sign*x[i] + y_sign*y[i] + z_sign*z[i]);
		}

		LL sum = 0;
		for(int i=0;i<M;i++){
			sum += pq.top();
			pq.pop();
		}
		ans = max(ans,sum);
	}
}
 
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> x[i] >> y[i] >> z[i];
 
    solve();
 
    cout << ans << endl;
    return 0;
}