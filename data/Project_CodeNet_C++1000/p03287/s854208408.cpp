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
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,M;
LL A[100000];
 
LL ans = 0;

void solve(){
	//A[0]~A[j-1]まで足してMで割ったあまりをA_accum[j]と呼ぶ
	vector<LL> A_accum(N+1,0);
	for(int i=0;i<N;i++) A_accum[i+1] = (A_accum[i] + A[i])%M;

	//A_accumのうちMで割ったあまりがiになるものが何個あるかをremof_M[i]とする
	map<LL,LL> remof_M;
	for(int i=0;i<=N;i++){
		remof_M[A_accum[i]]++;
	}

	//A_accum[i]をMで割ったあまりを見る
	for(int i=0;i<=N;i++){
		//-1は自身同士で引くと0になるためこれを除外するためのもの
		LL num = remof_M[A_accum[i]]-1;
		ans += num;
	}
	ans /= 2;
}
 
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
    	cin >> A[i];
    	A[i] %= M;
    }
 
    solve();
 
    cout << ans << endl;
    return 0;
}