#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N, K;
ll dp[2][41];//0:小さい 1:同じ
ll bit[41];
int main(){
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        ll A;
        cin >> A;
        for(int j = 0; j < 40; j++){
           if((A >> j) & 1) bit[j]++; 
        }
    }
    for(int i = 39; i >= 0; i--){
        if(dp[0][i + 1] != 0) dp[0][i] = dp[0][i + 1] + max(bit[i], N - bit[i]) * ((ll)1 << i);
        
        if((K >> i) & 1){
            dp[1][i] = dp[1][i + 1] + (N - bit[i]) * ((ll)1 << i);
            dp[0][i] = max(dp[0][i], dp[1][i + 1] + bit[i] * ((ll)1 << i));
        }else{
            dp[1][i] = dp[1][i + 1] + bit[i] * ((ll)1 << i);
        }
    }

    cout << max(dp[0][0], dp[1][0]) << endl;
    return 0;
} 