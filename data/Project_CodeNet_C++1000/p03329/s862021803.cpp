#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000

// xの累乗円のコインを生成
void make_multiplier(int x, int N, vector<int>& coins) {
    int num = x;
    while(num <= N) {
        coins.push_back(num);
        num *= x;
    }
}

int main() {
    int N;
    cin >> N;
    // DPテーブルを生成、初期化
    int dp[100010];
    for(int i = 0;i < 100010;i++) dp[i] = INF;
    dp[0] = 0;

    // コイン生成
    vector<int> coins = {1};
    make_multiplier(6, N, coins);
    make_multiplier(9, N, coins);

    sort(coins.begin(), coins.end());
    unique(coins.begin(), coins.end());

    // i番目までのコインを使ってj円引き出すときの最小回数
    int m = coins.size();
    for(int i = 0;i < m;i++) {
        int j = 0;
        while(j + coins.at(i) <= N) {
            if(dp[j + coins.at(i)] > dp[j] + 1) dp[j + coins.at(i)] =  dp[j] + 1;
            j++;
        }
    }

    cout << dp[N] << endl; // N円引き出すときの最小枚数
}