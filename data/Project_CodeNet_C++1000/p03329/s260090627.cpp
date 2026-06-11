#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    int INF = 100000;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i = 1; i < n+1; i++){
        dp[i] = 1 + dp[i-1];
        int power = 6;
        while(power <= i){
            dp[i] = min(dp[i], dp[i-power]+1);
            power *= 6;
        }
        power = 9;
        while(power <= i){
            dp[i] = min(dp[i], dp[i-power]+1);
            power *= 9;
        }
    }
    cout << dp[n] << endl;
    return 0;
}