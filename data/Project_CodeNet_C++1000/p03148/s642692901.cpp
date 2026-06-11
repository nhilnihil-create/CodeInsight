//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_e
//参考
//https://misteer.hatenablog.com/entry/ABC116
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
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,K;
vector<priority_queue<LL>> dish;//種類iの美味しさを持つ寿司の集合をdish[i]とおく

LL ans = 0;

void solve(){
    priority_queue<LL> best, remain;
    // best: 各種類で一番美味しいやつを集めたもの
    // remain : bestの余り
    for (int i = 0; i < N; ++i) {//種類iの寿司の集合を見ていく
        if (!dish[i].empty()) {//種類iの寿司がまだ1個以上あるなら
            best.push(dish[i].top());//種類iで一番美味しい寿司は優先度付きキューの頭にある
            dish[i].pop();

            while (!dish[i].empty()) {//残りは全部remain行き
                remain.push(dish[i].top());
                dish[i].pop();
            }
        }
    }
    //best,remainはpriority_queueなので勝手に降順にソートされる

    vector<LL> bsum = {0};
    // bestの累積和 (bsum[i] = bestの先頭からi個の総和)
    while (!best.empty()) {
        bsum.push_back(bsum.back() + best.top());
        best.pop();
    }

    vector<LL> rsum = {0};
    // remainの累積和
    while (!remain.empty()) {
        rsum.push_back(rsum.back() + remain.top());
        remain.pop();
    }

    //前者から、美味しい順にx個食べる。 (x種類の確保)
	//後者から、美味しい順にK−x個食べる。
	//この時点で、取った寿司の種類数はx以上K以下
    for (LL x = 1; x <= K; ++x) {
        // 種類が多すぎるケース
        if (x >= bsum.size()) break;

        // 種類が少なすぎて、余り物が足りないケース
        if (K - x >= rsum.size()) continue;

        // bestからx個、remainからK-x個貪欲に美味しい方から選ぶ
        ans = max(ans, bsum[x] + rsum[K - x] + x * x);
    }

}
 
int main(){
	cin >> N >> K;
	dish = vector<priority_queue<LL>>(N);
	for(int i=0;i<N;i++){
		int t,d;
		cin >> t >> d;
		t--;
		dish[t].push(d);
	}
 
	solve();

	cout << ans << endl;
	return 0;
}