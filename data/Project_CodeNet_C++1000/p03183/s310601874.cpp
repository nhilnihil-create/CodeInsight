// 以下のソースを勉強する.
// zscoder氏.
// https://atcoder.jp/contests/dp/submissions/3943024
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool cmp(pair<pair<LL, LL>, LL> a, pair<pair<LL, LL>, LL> b){
    if(a.first.first + a.first.second != b.first.first + b.first.second){
        return a.first.first + a.first.second < b.first.first + b.first.second;
    }
    return (a.second < b.second);
}

LL dp[1111][21111];
const int C = 20111;

int main(){
    
    // 1. 入力情報取得.
    vector<pair<pair<LL, LL>, LL>> vec;
    int N;
    scanf("%d", &N);
    vec.push_back({{-int(1e9), -1}, -1});
    for(int i = 0;i < N; i++){
        LL w, s, v;
        scanf("%lld %lld %lld", &w, &s, &v);
        vec.push_back({{w, s}, v});
    }
    
    // 2. dp更新.
    sort(vec.begin(), vec.end(), cmp);
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0;j <= C; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - vec[i].first.first >= 0 && vec[i].first.second >= j - vec[i].first.first){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - vec[i].first.first] + vec[i].second);
            }
        }
    }
    
    // 3. 出力.
    LL ans = 0;
    for(int j = 0; j <= C; j++) ans = max(ans, dp[N][j]);
    printf("%lld\n", ans);
    return 0;
    
}