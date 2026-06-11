#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18L + 5;
long long int* A;

long long int sum(int i, int j){
    long long int tot = 0;
    for(int k = i; k <= j; k++){
        tot += A[k];
    }
    return tot;
}

int main(){
    int N;
    cin>>N;
    long long int dp[N+1][N+1];
    A = new long long int[N+1];

    for(int i=1; i<= N; i++){
        cin>>A[i];
        dp[i][i] = 0;
    }

    for(int l=2; l<= N; l++){
        for(int i=1; i<= N - l + 1; i++){
            int j = i + l -1;

            long long int temp = sum(i, j);
            dp[i][j] = INF;

            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + temp);
            }
        }
    }

    cout<<dp[1][N];

    return 0;
}
