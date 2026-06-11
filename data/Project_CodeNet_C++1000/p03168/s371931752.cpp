#include<iostream>
#include<iomanip>
#define MAX_N 3000

using namespace std;

int N;
double p[MAX_N];
double dp[MAX_N][MAX_N];

int main(){
    cin >> N;
    for(int i=0;i < N;i++){
        cin >> p[i];
    }
    dp[0][0] = 1;

    for(int i=0;i < N;i++){
        for(int j=0;j <= i;j++){
            dp[i+1][j] += (1-p[i])*dp[i][j];
            dp[i+1][j+1] += p[i]*dp[i][j];
        }
    }
    double ans = 0.0;
    for(int i=N/2+1;i <= N;i++) ans += dp[N][i];
    cout << fixed << setprecision(10) <<  ans << endl;
    return 0;
}