#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

int a[1000000][3];
int dp[1000000][3];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<3;i++) dp[0][i]=a[0][i];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i][1];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+a[i][2];
    }

    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << endl;
}