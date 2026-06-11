
#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
そこまでの　A数とAB数を記録する?
AB数...以前のAB数 + もしそこがBなら 1*以前のA数
ABC数...以前のABC数+ もしそこがCなら 1*以前のC数

ここに?の概念を追加できるか

A数は以前のは単純に3倍 + 1　かなあ
AB数...以前のAB数*3 + もしそこがBなら以前のA数
ABC数...以前のABC数*3 + もしそこがCなら以前のAB数
*/

ll dp[100000][4];

int main() {
    string S;
    cin >> S;
    ll D = 1e9 + 7;
    dp[0][0] = 1;

    for (int i = 1; i <= S.length(); i++) {
        for (int j = 0; j < 4; j++) {
            if (S[i-1] == '?') dp[i][j] = (dp[i-1][j]) * 3 % D;
            else dp[i][j] = dp[i-1][j]% D;
        }
        if (S[i-1] == 'A' || S[i-1] == '?') dp[i][1] = (dp[i][1] + dp[i-1][0]) % D;
        if (S[i-1] == 'B' || S[i-1] == '?') dp[i][2] = (dp[i][2] + dp[i-1][1]) % D;
        if (S[i-1] == 'C' || S[i-1] == '?') dp[i][3] = (dp[i][3] + dp[i-1][2]) % D;
    }

    cout << dp[S.length()][3] % D << endl;    
}