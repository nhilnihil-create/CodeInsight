//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/cf17-final/tasks/cf17_final_c

//参考：https://www.hamayanhamayan.com/entry/2017/11/27/224728
 
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
LL D[50];
 
LL ans = 0;
 
void solve(){
	//時間iの人の人数をcount[i]とする
	vector<int> count(13,0);
	//時間iの人が存在するかどうか(詳しくは後述)
	vector<int> vis(24,0);

	for(int i=0;i<N;i++) count[D[i]]++;

	//count[0]>=1 = 高橋くんの都市と時差が0時間の都市が存在 = 答えは0
    if (count[0]) return;
    vis[0] = 1;//時間0にはすでに高橋くんがいる

    //時間i,jの人間が両方存在するならば
    //2人の時差をとる
    //というのを0<=i<=23,0<=j<=23について繰り返し、
    //時差の最小値を返す
    auto counter = [&](){
    	LL mi = INF_INT;
    	for(int i=0;i<24;i++){
    		for(int j=0;j<24;j++){
    			if(vis[i] && vis[j] && i!=j){
    				LL d1 = abs(i-j);
    				LL d2 = 24 - abs(i-j);
    				mi = min(mi,min(d1,d2));
    			}
    		}
    	}
    	return mi;
    };

 	// count[t] == 0ならば人はいない。
	// count[t] == 1ならば時間tか時間(24-t)のどちらかに人がいる。これは分からないので全探索で考える。
	// count[t] == 2ならば時間tか時間(24-t)のどちらにも人がいる。ここは確定。
	//        時刻の差のうちの最小値をsとし、考えうる最大値を求めているため、
	//        count[t]==2の時t,24-tどちらかに2人入れてしまうとs=0になってしまう
	//        このsは絶対に最大値の候補にはなり得ないので除外して良い
	// 2 ≦ count[t]ならば、どうやっても2人以上いる時間が出来てしまうので、答えは0
    vector<int> v;//全探索が必要な時間を格納(最大でも要素数は1~11の11個)
    for(int i=1;i<12;i++) {
        if(count[i] == 1) v.push_back(i);
        else if(count[i] == 2) vis[i] = vis[24 - i] = 1;
        else if(2 < count[i]) return;
    }
    if (count[12] == 1) vis[12] = 1;
    else if (2 <= count[12]) return;//時間12に2人以上いたらその差がどうやっても0になってしまう
 
    int M = v.size();
    if (M == 0) {
    	ans = counter();
        return;
    }

 	// count[t]==1である部分だけを全探索して、距離の最小をチェックする。
	// 全探索する可能性があるtは[1,11]の11通りで全部でO(2^11)、最小のチェックを愚直にやってO(N^2)。
	// 全部でO(2^11*50*50)なので間に合う。
    for(int bit=0;bit<(1<<M);bit++){
    	//bitのi[bit]目が1なら　vis[v[i]] = 1(高橋くんから見て時計回り)
    	//bitのi[bit]目が0なら　vis[24 - v[i]] = 1(高橋くんから見て反時計回り)
    	//となるようbit全探索

    	//以下のfor内で、ビット列bitに対応するよう円形に配置、
    	//ラムダ式counter()で人と人同士の距離の最小値をはかる
        for(int i=0;i<M;i++){//全探索が必要な時間がvに保管してある(vは要素数M)
            if (bit & (1 << i)) vis[v[i]] = 1, vis[24 - v[i]] = 0;
            else vis[v[i]] = 0, vis[24 - v[i]] = 1;
        }
        ans = max(ans,counter());
    }
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> D[i];
 
    solve();
 
    cout << ans << endl;
    return 0;
}