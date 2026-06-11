#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

int main(void)
{
    int N;
    cin >> N;

    vector<vector<int>> A(2,vector<int>(N));
    REP(i,2){
        REP(j,N){
            cin >> A[i][j];
        }
    }

    int dp[5][110] = {0};

    dp[0][0] = A[0][0];
    dp[1][0] = A[0][0] + A[1][0];

    for(int j = 1; j < N; j++){
        dp[0][j] = dp[0][j-1] + A[0][j]; 
        dp[1][j] = max(dp[0][j], dp[1][j-1]) + A[1][j];
    }

    cout << dp[1][N-1] << endl;

    return 0;
}
