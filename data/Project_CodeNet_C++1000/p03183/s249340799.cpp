#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Block{
    int w, s, v;
    Block(int w, int s, int v) : w(w), s(s), v(v) {}
};

bool operator<(const Block &a, const Block &b){
    return a.w+a.s < b.w+b.s;
}

int main(){
    int N;
    cin >> N;
    vector<Block> B;
    for(int i = 0; i < N; ++i){
        int w, s, v;
        cin >> w >> s >> v;
        B.emplace_back(w,s,v);
    }
    sort(B.begin(),B.end());
    vector<long long> dp(2e4+1,-1);
    dp[0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = B[i].s; j >= 0; --j){
            if(j + B[i].w > 2e4) continue;
            dp[j+B[i].w] = max(dp[j+B[i].w],dp[j]+B[i].v);
        }
        for(int j = 1; j <= 2e4; ++j)
            dp[j] = max(dp[j],dp[j-1]);
    }
    cout << dp.back() << endl;
}
