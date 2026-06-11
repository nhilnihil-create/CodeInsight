#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

int N;
vector<vector<vector<double>>> dp;

double rec(int i, int j, int k){
    if (dp[i][j][k]>=0) return dp[i][j][k];
    if (i==0&&j==0&&k==0) return 0.0;

    double res = 0.0;
    if (i>0) res += rec(i-1,j,k)*i;
    if (j>0) res += rec(i+1,j-1,k)*j;
    if (k>0) res += rec(i,j+1,k-1)*k;
    res += (double)N;
    res *= 1.0 / (double)(i + j + k);

    return dp[i][j][k] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int one = 0, two = 0, three = 0;
    for (int i=0;i<N;i++){
        int a;
        cin >> a;
        if (a == 1) one++;
        else if (a==2) two++;
        else three++;
    }
    dp = vector<vector<vector<double>>>(N+5,vector<vector<double>>(N+5,vector<double>(N+5,-1)));

    cout << fixed << setprecision(9) << rec(one, two, three) << "\n";
}