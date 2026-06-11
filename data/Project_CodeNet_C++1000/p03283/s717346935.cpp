//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc106/tasks/abc106_d

//参考：
//http://tutuz.hateblo.jp/entry/2018/08/19/064525

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

LL N,M,Q;
LL L[200000],R[200000];
LL p[100000],q[100000];

vector<LL> ans;

void solve(){
	//始点start,終点endの列車の数をtrain[start][end]とする
	vector<vector<LL>> train(N+1,vector<LL>(N+1,0));
	for(int i=0;i<M;i++){
		train[L[i]][R[i]]++;
	}
	//train[1][1] ~ train[x][y]の長方形の領域に含まれる
	//列車の数の和をaccum[x][y]とおく
	vector<vector<LL>> accum(N+1,vector<LL>(N+1,0));
	for(int h=1;h<=N;h++){
		for(int w=1;w<=N;w++){
			accum[h][w] = accum[h][w-1] + train[h][w];
		}
	}
	for(int h=1;h<=N;h++){
		for(int w=1;w<=N;w++){
			accum[h][w] = accum[h][w] + accum[h-1][w];
		}
	}
	for(int i=0;i<Q;i++){
		ans.push_back(accum[q[i]][q[i]] - accum[p[i]-1][q[i]]);
	}
}

int main(){
    cin >> N >> M >> Q;
    for(int i=0;i<M;i++) cin >> L[i] >> R[i];
    for(int i=0;i<Q;i++) cin >> p[i] >> q[i];

    solve();

	for(int i=0;i<Q;i++) cout << ans[i] << endl;
    return 0;
}