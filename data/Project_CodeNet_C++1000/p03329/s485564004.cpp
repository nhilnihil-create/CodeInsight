#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;

int main(void){
    ll N;
    cin >> N;
    
    vector<ll> dp(110000,INF);
    dp[0] = 0;
    int num;
    
    for(int i = 1; i <= N; i++){
        num = 1;
        while(num <= i){
            dp[i] = min(dp[i], dp[i-num]+1);
            num *= 6;
        }
        
        num = 1;
        while(num <= i){
            dp[i] = min(dp[i], dp[i-num]+1);
            num *= 9;
        }
    }
    cout << dp[N] << endl;
    return 0;
}