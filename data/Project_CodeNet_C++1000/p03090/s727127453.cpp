//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc032/tasks/agc032_b

//参考：
//ポイント：
//https://drken1215.hatenablog.com/entry/2019/03/24/110200

//全体から引く
//完全グラフを考えて、そこから引いて考える

//ただ2部グラフ、完全グラフ、スター、パスなどを考えるだけでなく
//そこから辺や点を取り除くことも重要


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

LL N;

vector<pair<LL,LL>> ans;

void solve(){
	if(N==3){
		ans.push_back(pair<LL,LL>(1,3));
		ans.push_back(pair<LL,LL>(2,3));
		return;
	}
	for(int i=1;i<=N - N%2;i++){
		for(int j=i+1;j<=N - N%2;j++){
			if((1+N - N%2)!=(i+j)) ans.push_back(pair<LL,LL>(i,j));
		}
	}
	if(N%2==1){
		for(int k=1;k<=N-1;k++) ans.push_back(pair<LL,LL>(k,N));
	}
}
 
int main(){
    cin >> N;
 
    solve();

    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}