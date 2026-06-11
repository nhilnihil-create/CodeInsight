//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc098/tasks/arc098_b

//ポイント：
//「xor 和と加算和とが等しい」という条件下では
//「条件を満たす区間の部分区間も条件を満たす」という構造を作れる
//基本的に「xor 和 <= 加算和」
//加算和には繰り上がりがあるため

//参考：https://drken1215.hatenablog.com/entry/2018/06/26/125054

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

LL N;
LL A[200000];
 
LL ans = 0;

void solve(){
	//尺取り法
	LL add_sum = A[0];
	LL xor_sum = A[0];
	//今見てる範囲を[left,right)で表す
	int right = 1;
	for(int left=0;left<N;left++){
		while(right<=N-1 && ((xor_sum^A[right]) == add_sum+A[right])){
			xor_sum ^= A[right];
			add_sum += A[right];
			right++;
		}
		ans += (right-left);
		if(left==right){
			xor_sum ^= A[right];
			add_sum += A[right];
			right++;
		}
		else{
			xor_sum ^= A[left];
			add_sum -= A[left];
		}
	}
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();
 
    cout << ans << endl;
    return 0;
}