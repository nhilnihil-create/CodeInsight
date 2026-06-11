//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/exawizards2019/tasks/exawizards2019_c

//2部探索が使える場合：
//nで成り立つ時、n-1でも成り立つみたいな時

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
#include <stack>
#include <map> 
#include <unordered_map> 
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

LL N,Q;
string S;
char T[200000],D[200000];

LL ans = 0;

//左から押し出されるなら-1
//押し出されないなら0
//右から押し出されるなら1を返す
int simulate(int index){
	int p = index;
	for(int i=0;i<Q;i++){
		if(S[p]==T[i]){
			if(D[i]=='L') p--;
			if(D[i]=='R') p++;
			if(p<0) return -1;
			if(p>=N) return 1;
		}
	}
	return 0;
}

void solve(){
	//左から何番目までが左から押し出されるか
	int L;
	{
		int left = 0;
		int right = N;
		while(left+1<right){
			int center = (left+right)/2LL;
			if(simulate(center)==-1) left = center;
			else right = center;
		}
		L = left;
	}

	//右から何番目までが左から押し出されるか
	int R;
	{
		int left = 0;
		int right = N;
		while(left+1<right){
			int center = (left+right)/2LL;
			if(simulate(center)==1) right = center;
			else left = center;
		}
		R = right;
	}

	ans = R - L - 1;
}

int main(){
    cin >> N >> Q;
    cin >> S;
    for(int i=0;i<Q;i++) cin >> T[i] >> D[i];

    solve();

    cout << ans << endl;
    return 0;
}