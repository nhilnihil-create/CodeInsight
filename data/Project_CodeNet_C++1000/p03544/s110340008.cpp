#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

long long LucaNum(int n);

int main(){
    int N;
    cin >> N;

    vector<long long> dp(N+1,0);

    dp[0] = 2;
    dp[1] = 1;

    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N] << endl;
    return 0;

}

