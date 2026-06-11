#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    const long long INF = 1LL << 60;


    long long N;
    cin >> N;

    // DP テーブル
    long long dp[N + 10];

    // DP テーブル全体を初期化 (最小化問題なので INF に初期化)
    for (int i = 0; i < N + 10; ++i) dp[i] = INF;

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 0; i < N+1; i++){
            long long s = 1;
            long long t = 1;
        for(int j = 1; j < N; j++){
          if(i - j <0)break;
            chmin(dp[i],dp[i - 1] + 1) ;
            s *= 6;
            if(i - s>=0){
                chmin(dp[i],dp[i - s] + 1);
            }
            t *= 9;
            if(i - t>=0){
                chmin(dp[i],dp[i - t] + 1);
            }
            if(i - s < 0 && i - t < 0)break;
        }
    }

    cout << dp[N] << endl;
}
