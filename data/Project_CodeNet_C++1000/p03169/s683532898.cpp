#include <bits/stdc++.h>
using namespace std;
double dp[301][301][301];
int n;
double rec(int i, int j, int k)
{
    if(dp[i][j][k]) return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0) return 0;
    double res = 0;
    if(i > 0) res += rec(i-1, j, k) * i;
    if(j > 0) res += rec(i+1, j-1, k) * j;
    if(k > 0) res += rec(i, j+1, k-1) * k;
    res += n;
    res /= i+j+k;
    return dp[i][j][k] = res;
}
int main()
{
    cin >> n;
    int one = 0;
    int two = 0;
    int three = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a == 1) one++;
        if(a == 2) two++;
        if(a == 3) three++;
    }
    memset(dp, 0, sizeof(dp));
    cout << fixed << setprecision(10) <<  rec(one, two, three) << endl;
}


