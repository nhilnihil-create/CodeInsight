//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc081/tasks/arc086_b

//ポイント：
//正負の数が混ざっている時は正負どちらかに統一してから考えるといいかも

//参考：
//https://aralmath.hatenablog.com/entry/2019/02/23/231330

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
LL A[51];

vector<pair<LL,LL>> ans;

void solve(){
	LL max=0;//絶対値最大のやつ
    int max_index=0;//それの番号
    
    for(int i=1;i<=N;i++){
        if(abs(A[i])>=abs(max)){
            max=A[i];
            max_index=i;
        }
    }
    
    //Step 1:絶対値最大のやつを他に足して符号を揃える
    for(int i=1;i<=N;i++) ans.push_back(pair<LL,LL>(max_index,i));
    
    //Step 2:前or後ろから順に足していく
    //maxが正なら、Step1でAの要素は全部正になる
    if(max>=0){
        for(int i=1;i<=N-1;i++) ans.push_back(pair<LL,LL>(i,i+1));
    }
    //maxが負なら、Step1でAの要素は全部負になる
    else{
        for(int i=N;i>=2;i--) ans.push_back(pair<LL,LL>(i,i-1));
    }
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
 
    solve();

	cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}