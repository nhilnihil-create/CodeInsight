//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc096/tasks/abc096_d

//ポイント：
//自由に生成する問題では如何に条件を絞れるかが重要

//5つの数の和が合成数
//合成数の集合をまず考える
//合成数という集合の中には5の倍数が含まれる
//5つの数の和が5の倍数であるようにするには、5つの数の一桁めが全部同じなら良い

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

//xが素数ならtrueを返す
bool factorial(LL x){
	for(LL i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

LL N;
 
vector<LL> ans;

void solve(){
	vector<LL> prime;
	for(int i=3;i<=55555;i++){
		if(factorial(i)) prime.push_back(i);
	}
	for(int i=0;i<prime.size() && ans.size()<N;i++){
		if(prime[i]%10==1) ans.push_back(prime[i]);
	}
}

int main(){
    cin >> N;
 
    solve();
 
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    return 0;
}