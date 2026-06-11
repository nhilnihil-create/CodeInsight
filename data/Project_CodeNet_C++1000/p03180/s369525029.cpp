//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/dp/tasks/dp_u

//参考：https://www.hamayanhamayan.com/entry/2019/01/12/151211

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
LL a[16][16];
 
LL ans = 0;

void solve(){
	//dp[bit] := グループが決まったうさぎがbitである場合の点数の最大値
	vector<LL> dp(1<<N,0);
	//cst[bit] := bitの立ったうさぎを全部同じグループに入れたときの点数
	vector<LL> cst(1<<N,0);

    for(int bit=0;bit<(1<<N);bit++){
        for(int i=0;i<N;i++){//i番目のウサギを見ていく
        	for(int j=i+1;j<N;j++){//i+1~N-1番目のウサギを見る
        		//bitのうちi,jビット目が両方1なら同じグループに入っているとみなし、
        		//cst[bit]に対応するスコアを格納

        		//例えばbit=01001なら1番目と4番目のウサギを見ることを表し、
        		//cst[01001] = a[1][4]となる
        		//cst[01011] = a[1][3] + a[1][4] + a[3][4]となる
        		if((bit&(1<<i)) && (bit&(1<<j))) cst[bit] += a[i][j];
        	}
        }
    }
 
    for(int bit=0;bit<(1<<N);bit++){
    	//sub_bitはbitの部分集合
    	//forでbitの部分集合を0を除いて全て列挙
    	//例えばbit=110なら110,100,010の3つを調べる

    	//0~bitに収まる全てのビット列はそれぞれ、bitとandをとると
    	//bitの部分集合を全部列挙できる
        for(int sub_bit=bit;sub_bit>0;sub_bit=(sub_bit-1)&bit){
        	//dp[bit] = dp[bit - sub_bit] + cst[sub_bit]
        	//とは、すでにbit-sub_bitで表されるウサギについて
        	//グループ分けが決まっている時、sub_bitで表されるウサギを
        	//新たに1グループ作って全部それに入れることを表す
            dp[bit] = max(dp[bit],dp[bit - sub_bit] + cst[sub_bit]);
        }
    }
 
    ans = dp[(1<<N)-1];
}

int main(){
    cin >> N;
    for(int h=0;h<N;h++){
    	for(int w=0;w<N;w++) cin >> a[h][w];
    }
 
    solve();

    cout << ans << endl;
    return 0;
}