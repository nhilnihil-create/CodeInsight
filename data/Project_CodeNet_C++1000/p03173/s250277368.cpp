#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

#define chmin(x, y) x = min(x, y)

// 入力
int n;
vector<long long> a;
// dp[left][right] := 区間 [left,right) におけるコストの最小値
vector<vector<long long>> dp(405, vector<long long>(405, -1));
// スライムの大きさの累積和
long long S[405];

// メモ化再帰
long long memo_rec(int left, int right){
    if(dp[left][right] != -1)   return dp[left][right];
    if(right - left == 1)   return dp[left][right] = a[left];
    if(right - left < 1)    return 0;   // これは必要なわけではない

    long long res = numeric_limits<long long>::max();
    for(int pos = left + 1; pos < right; ++pos){
        long long tmp = 0;
        if(pos - left > 1)  tmp += memo_rec(left, pos) + S[pos] - S[left];
        else    tmp += memo_rec(left, pos);
        if(right - pos > 1) tmp += memo_rec(pos, right) + S[right] - S[pos];
        else    tmp += memo_rec(pos, right);
        chmin(res, tmp);
    }
    return dp[left][right] = res;
}

int main(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        S[i+1] = S[i] + a[i];
    }
    cout << memo_rec(0, n) << endl;
}