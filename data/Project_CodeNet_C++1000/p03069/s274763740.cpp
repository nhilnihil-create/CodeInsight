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
 
LL N;
string S;
 
int ans = INF_INT;
 
void solve(){
    //最終的に......######みたいな列ができれば良い
    //各石について、色を黒→白にするか白→黒にするかを
    //考えようとするとTLEする

    //なのでN+1通りの境界について考えていく
    //sum[BLACK][LEFT] = 境界より左側の、黒の個数
    //sum[BLACK][RIGHT] = 境界より右側の、黒の個数
    //WHITEについても同様
    const int BLACK = 0;
    const int WHITE = 1;
    const int LEFT = 0;
    const int RIGHT = 1;
    vector<vector<int>> sum(2,vector<int>(2,0));
    for(int i=0;i<N;i++){
        if(S[i]=='#') sum[BLACK][RIGHT]++;
        if(S[i]=='.') sum[WHITE][RIGHT]++;
    }
    //左から順に調べる
    //i-1個目とi個目に境界を配置する
    for(int i=0;;i++){
        // for(int j=0;j<N;j++){
        //     if(i==j) cout << "|";
        //     cout << S[j];
        // }
        // cout << endl;
        // cout << sum[WHITE][LEFT] << " " << sum[WHITE][RIGHT] << endl;
        // cout << sum[BLACK][LEFT] << " " << sum[BLACK][RIGHT] << endl << endl;
        ans = min(ans,sum[BLACK][LEFT]+sum[WHITE][RIGHT]);
        if(i>=N) break;
        if(S[i]=='#'){
            sum[BLACK][LEFT]++;
            sum[BLACK][RIGHT]--;
        }
        if(S[i]=='.'){
            sum[WHITE][LEFT]++;
            sum[WHITE][RIGHT]--;
        }
    }
}
 
int main(){
    cin >> N;
    cin >> S;
 
    solve();
 
    cout << ans << endl;
    return 0;
}