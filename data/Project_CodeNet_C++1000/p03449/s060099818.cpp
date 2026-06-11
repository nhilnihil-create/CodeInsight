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

    vector<vector<int>> A(5,vector<int>(110));
    REP(i,2){
        REP(j,N){
            cin >> A[i][j];
        }
    }

    int dp[5][110] = {0};

    dp[0][0] = A[0][0];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + A[i + 1][j]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + A[i][j + 1]);
        }
    }
    cout << dp[1][N-1] << endl;

    return 0;
}
