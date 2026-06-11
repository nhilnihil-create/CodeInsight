#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;

// マッチの本数を教えてくれる美人なお姉さん
int num(int a){
    switch(a){
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 6;
        default:
            return 0;
    }
}

int main(void){
    int n,m; cin >> n >> m;
    vector<int> a(m); rep(i,m) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    vector<int> dp(n+1,-1); // dp[i]: ちょうどi本のマッチ棒で作れる整数の最大桁数を教えてくれる美人なお姉さん
    // dpを計算してくれるお姉さん
    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        rep(j,m){
            if(i - num(a[j]) >= 0){
                dp[i] = max(dp[i], dp[i-num(a[j])] + 1);
            }
        }
    }
    // 求める整数を出力してくれるお姉さん
    while(n >= 2){
        rep(j,m) if((n - num(a[j]) >= 0) /*参照エラー防止*/ && (dp[n-num(a[j])] == dp[n]-1)){
            cout << a[j];
            n -= num(a[j]);
            break;
        }
    }
}