//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc032/tasks/agc032_a

//参考
//https://drken1215.hatenablog.com/entry/2019/03/24/091900

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
vector<LL> B;
 
vector<LL> ans;
 
void solve(){
    for(int i=0;i<N;i++){
        int pivot = -1;
        //Bを後ろから順に見ていき
        //B[j]==jとなるようなものがあったらその時点でループを打ち切る
        for(int j=B.size()-1;j>=0;j--){
            if(B[j]==j+1){
                pivot = j;
                break;
            }
        }
        if(pivot == -1){
            ans = vector<LL>(1,{-1});
            return;
        }

        ans.push_back(pivot + 1);
        B.erase(B.begin() + pivot);
    }
    reverse(ans.begin(),ans.end());
}
 
int main(){
    cin >> N;
    B = vector<LL>(N);
    for(int i=0;i<N;i++) cin >> B[i];
 
    solve();
 
    for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
    return 0;
}