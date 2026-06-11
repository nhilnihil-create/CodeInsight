#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)

int main(){
    int num[10];
    num[1] = 2, num[2] = 5, num[3] = 5, num[4] = 4, num[5] = 5;
    num[6] = 6, num[7] = 3, num[8] = 7, num[9] = 6;
    int N, M;
    cin >> N >> M;
    int A[M];
    rep(i, M){
        cin >> A[i];
    }
    long long dp[N+1];
    dp[0] = 0;
    rep2(i, 1, N+1){
        long long ans = -10000000000;
        rep(j, M){
            int k = i - num[A[j]];
            if(k >= 0){
                ans = max(ans, dp[k]+1);
            }
        }
        dp[i] = ans;
    }
    sort(A, A+M, greater<int>());
    long long n = dp[N];
    long long x = N;
    int res[n];
    while(n > 0){
        rep(i, M){
            if(dp[x-num[A[i]]] == n-1){
                x -= num[A[i]];
                n--;
                res[n] = A[i];
                break;
            }
        }
    }
    for(int i = dp[N]-1; i >= 0; i--){
        cout << res[i];
    }
}