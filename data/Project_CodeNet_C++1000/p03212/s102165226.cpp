#include<iostream>
#include<vector>
#include<string>
#include<cstring>

// ref : http://kyopro.hateblo.jp/entry/2018/12/25/174720

using ll = long long;
/*
dp[d][smaller][leadingZero][num]
numは3, 5, 7を少なくとも1回選んだかどうかのフラグとする
具体的には3bit(つまり0 ~ 7)のうち各bitで管理する
leadingZero = 0 はまだ0が続いている状態
*/
ll dp[11][2][2][8];

int main(){
    std::string S;
    std::cin >> S;

    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = 1;
    for(int d = 0; d < S.size(); d++){
        for(int smaller = 0; smaller < 2; smaller++){
            for(int leadingZero = 0; leadingZero < 2; leadingZero++){
                for(int num = 0; num < 8; num++){
                    if(dp[d][smaller][leadingZero][num] == 0) continue; // 足す意味なし

                    int val; // 次に入れられる数字の最大値
                    if(smaller == 1){
                        val = 9;
                        if(leadingZero == 0){
                            // まだ0が続いている状態
                            // 必ず小さいのでsmallerは1
                            // dp[d + 1][1][leadingZero][0] += dp[d][smaller][leadingZero][num];
                            dp[d + 1][1][leadingZero][0] = 1;
                        }
                    }else{
                        val = S[d] - '0';
                        if(leadingZero == 0){
                            // まだ0が続いている状態
                            // 必ず小さいのでsmallerは1
                            //dp[d + 1][1][leadingZero][0] += dp[d][smaller][leadingZero][num];
                            dp[d + 1][1][leadingZero][0] = 1;
                        }
                    }

                    // valの値に応じてsmallerを切り替えて計算
                    if(val == 3) dp[d + 1][0][1][num | 1] += dp[d][smaller][leadingZero][num];
                    if(val > 3) dp[d + 1][1][1][num | 1] += dp[d][smaller][leadingZero][num];
                    if(val == 5) dp[d + 1][0][1][num | 2] += dp[d][smaller][leadingZero][num];
                    if(val > 5) dp[d + 1][1][1][num | 2] += dp[d][smaller][leadingZero][num];;
                    if(val == 7) dp[d + 1][0][1][num | 4] += dp[d][smaller][leadingZero][num];;
                    if(val > 7) dp[d + 1][1][1][num | 4] += dp[d][smaller][leadingZero][num];
                }
            }
        }
    }

    std::cout << dp[S.size()][0][1][7] + dp[S.size()][1][1][7] << std::endl;
    return 0;
}
