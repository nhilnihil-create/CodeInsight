#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300;
vector<vector<vector<double>>> dp(N+2,vector<vector<double>>(N+2,vector<double>(N+2,-2)));

double solve(int x,int a,int b,int c)
{
    if(dp[a][b][c]>-1) return dp[a][b][c];
    dp[a][b][c]=1;
    double s=(x+a+b+c);
    if(a>0) dp[a][b][c]+=((a/s)*solve(x+1,a-1,b,c));
    if(b>0) dp[a][b][c]+=((b/s)*solve(x,a+1,b-1,c));
    if(c>0) dp[a][b][c]+=((c/s)*solve(x,a,b+1,c-1));
    dp[a][b][c]/=(1-(x/s));
    return dp[a][b][c];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cnt(4,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    dp[0][0][0]=0;
    cout << fixed << setprecision(14) << solve(0,cnt[1],cnt[2],cnt[3]) << "\n";
    return 0;
}
