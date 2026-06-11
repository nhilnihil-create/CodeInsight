//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc020/tasks/agc020_b

//参考：
//http://ch3000.blog.fc2.com/blog-entry-44.html

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

LL K;
LL A[100001];

LL ans_min = 2,ans_max = 2;

void solve(){
	for (int i=K;i>=1;i--) {
		//最小化
		ans_min = A[i] * ceil(ans_min / (A[i] + .0));
		//最大化
		ans_max = A[i] * (ans_max / A[i]) + A[i] - 1;
	}
	if (ans_min > ans_max) ans_min = -1;
}

int main(){
    cin >> K;
    for(int i=1;i<=K;i++) cin >> A[i];

    solve();

	if(ans_min==-1){
		cout << -1 << endl;
		return 0;
	}
	cout << ans_min << " " << ans_max << endl;
    return 0;
}