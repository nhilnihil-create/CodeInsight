#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int dp[300010][2]; // Eは0,Wは1に対応,i番目より前(iを含めない）でEが何個Wが何個
    for(int i = 2; i <= n+1; i++){
        if(s.at(i-2) == 'W'){
            dp[i][1] = dp[i-1][1]+1;
            dp[i][0] = dp[i-1][0];
        }
        else{
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = dp[i-1][1];
        }
    }
    int ans = 1001001001;
    for(int i = 1; i <= n; i++){ //向きを変えるのはリーダーの左にあるWと右にあるE
        ans = min(ans, dp[i][1] + (dp[n+1][0] - dp[i+1][0]));
    }
    cout << ans << endl;
}