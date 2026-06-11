# include <bits/stdc++.h>
using namespace std;
# define lli long long int
# define MOD 1000000007
# define INF 10000000000009
# define MAX 1000000

double prob[3001];
double dp[3001][3001];

double findNum(int i, int h){
    if(h == 0)
        return 1;
    if(i == 0)
        return 0;

    if(dp[i][h] > -0.9){
        return dp[i][h];
    }

    return dp[i][h] = prob[i]*findNum(i - 1, h - 1) + (1 - prob[i])*findNum(i - 1, h);

}

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> prob[i];
    }

    memset(dp, -1, sizeof(dp));
    double ans = findNum(n, n/2 + 1);
    cout.precision(10);
    cout << ans;
}


int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
