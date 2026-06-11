#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int N;
    ll A,B;
    cin >> N >> A >> B;
    ll inf = 1e18;
    vector<int> l(N+1,0),p(N+1,0);
    for(int i=1;i<=N;i++) cin >> p[i];
    vector<vector<ll>> dp(N+1,vector<ll>(N+1,inf));
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
        if(p[j]==i) break;
        if(p[j]>i) l[i]++;
    }
    for(int j=0;j<=N;j++) dp[0][j] = 0;
    for(int i=1;i<=N;i++) for(int j=0;j<=N;j++){
        if(j<=l[i]){
            dp[i][j] = min(dp[i][j],dp[i-1][j]+B);
            dp[i][l[i]] = min(dp[i][l[i]],dp[i-1][j]);
        }else dp[i][j-1] = min(dp[i][j-1],dp[i-1][j]+A);
    }
    cout << dp[N][0] << endl;
}