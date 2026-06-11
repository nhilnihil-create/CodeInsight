//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/arc103/tasks/arc103_c

//参考：https://phyllo-algo.hatenablog.com/entry/2018/09/30/023710
//https://betrue12.hateblo.jp/entry/2018/09/30/125042

//キャタピラ木という木がある

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

string S;

int flag = -1;
vector<pair<LL,LL>> ans;

void solve(){
	int N = S.size();
	if(S[0]!='1' || S[N-1]!='0') return;
	for(int i=0;i<=(N-2)/2;i++){
		if(S[i]!=S[N-2-i]) return;
	}
	flag = 1;

	int focus = 1;
	int counter = 2;
	for(int i=0;i<=N-2;i++){
		ans.push_back(pair<LL,LL>(focus,counter));
		if(S[i]=='1') focus = counter;
		counter++;
	}
}

int main(){
    cin >> S;

    solve();
    if(flag==-1){
    	cout << -1 << endl;
    	return 0;
    }
    for(int i=0;i<ans.size();i++)cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}