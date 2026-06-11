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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL C[200000];

LL ans = 1;

void solve(){
    //ランレングス圧縮
    vector<LL> C_pressed;
    C_pressed.push_back(C[0]);
    for(int i=1;i<N;i++){
        if(C[i]!=C[i-1]) C_pressed.push_back(C[i]);
    }
    N = C_pressed.size();
    // for(int i=0;i<N;i++) cout << C_pressed[i] << " ";
    //     cout << endl;

    vector<LL> color_num(200001,0);
    color_num[C_pressed[0]]++;
    vector<LL> dp(N,0);
    dp[0] = 1;
    for(int i=1;i<N;i++){
        dp[i] = (dp[i-1] + color_num[C_pressed[i]])%mod;
        color_num[C_pressed[i]] = dp[i];
    }
    // for(int i=0;i<N;i++) cout << dp[i] << " ";
    // cout << endl;
    ans = dp[N-1];
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> C[i];
 
    solve();

    cout << ans << endl;
    return 0;
}