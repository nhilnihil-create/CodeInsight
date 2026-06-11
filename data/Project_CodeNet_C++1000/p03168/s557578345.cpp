#include <iostream>
#include <vector>
#include<iomanip>
#define ll long long;
using namespace std;
vector<long double> heads;
vector<vector<long double>> dp;
int N;
long double res = 0;
int count = 0;
// double solve(int pos = 0, int tailsCount = 0, bool isHead = true,long double prob = 1)
// {
//     count++;
//     if (pos == N){
//         // cout<<prob<<" ";

//         res += prob;
//         return prob;
//     }
//     long double headProb = heads[pos];
//     long double tailProb = 1 - heads[pos];
//     solve(pos + 1, tailsCount, true,headProb * prob);
//     if(tailsCount + 1 <= N/2)
//         solve(pos + 1, tailsCount + 1, false,tailProb * prob);
//     return prob;
// }

double solve(){
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= i;j++){
            if(j == 0){
                dp[i][j] = (1-heads[i-1]) * dp[i-1][j];
            }
            // else if(i == j){
            //     dp[i][j] = heads[i-1];
            // }
          else{
                dp[i][j] = (((1-heads[i-1]) * dp[i-1][j]) + (heads[i-1] * dp[i-1][j-1]));
            }

        }
    }
    //  for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= N;j++){
    //         cout<<dp[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    double ans = 0;
    for(int k = N; k > N/2;k--){
        ans += dp[N][k]; 
    }
    return ans;
}

int main()
{
    cin >> N;
    heads = vector<long double>(N);
    dp = vector<vector<long double>>(N+1,vector<long double>(N+1,0));
    for (int i = 0; i <= N; i++)
    {
        cin >> heads[i];
    }
    cout<<setprecision(10)<<solve() ;
    //cout<<setprecision(10)<<res<<" "<<count;
}