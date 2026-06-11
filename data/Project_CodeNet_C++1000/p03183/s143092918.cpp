/*解説AC*/

#include<bits/stdc++.h>
using namespace  std;
using Int = long long;
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
int main(){
    Int N;  cin >> N;
    using tup = tuple<Int,Int,Int,Int>;
    constexpr Int inf = -1 * (1LL << 60);
    vector<tup>input;
    for(int i = 0; i < N; ++i){
        int w,s,v; cin >> w >> s >> v;
        input.emplace_back(w + s, w,s,v);
    }
    // 優先順位を決めて、並び替える
    sort(input.begin(),input.end());
    // dp[i][j] := i番目のblockを使ったとき, weight のときの max_value
    
    vector<vector<Int>>dp(N + 1, vector<Int>(10000 * 3,inf));
    dp[0][0] = 0;
    for(int i = 0; i < N; ++i){
        Int w,s,v,g; tie(g,w,s,v) = input[i];
        for(int j = 0; j < dp[i].size(); ++j){
            if(dp[i][j] == inf) continue;
            cmax(dp[i + 1][j],dp[i][j]);
            if(s >= j){
                cmax(dp[i + 1][j + w], dp[i][j]  + v);
            }
        }
    }
    cout << *max_element(dp.back().begin(), dp.back().end()) << endl;
}
