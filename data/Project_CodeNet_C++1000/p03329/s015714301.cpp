#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int dp[100001];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < 100001;i++) dp[i] = n;
    dp[0] = 0;
    for (int i = 1;i <= n; i++){
        for (int pow6 = 1; pow6 <= i; pow6*=6) dp[i] = min(dp[i],dp[i-pow6]+1);
        for (int pow9 = 1; pow9 <= i; pow9*=9) dp[i] = min(dp[i],dp[i-pow9]+1);
    }
    cout << dp[n] << endl;
    

    return 0;

}
