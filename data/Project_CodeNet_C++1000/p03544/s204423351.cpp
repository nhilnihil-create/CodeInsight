#include <iostream>
#include <cstdio>
using namespace std;
long long dp[100];


long long L(long long n){
    if(n == 0){
        return 2;
    }
    else if(n == 1){
        return 1;
    }

    dp[0] = 2;
    dp[1] = 1;
    for(long long i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

}
int main(){
    long long n;
    cin >> n;

    cout << L(n) << endl;
    return 0;
}