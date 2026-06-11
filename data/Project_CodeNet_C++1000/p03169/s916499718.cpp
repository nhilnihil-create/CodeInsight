#include <bits/stdc++.h>

#define ld long double
#define MAXN 305

using namespace std;

int n;
ld dp[MAXN][MAXN][MAXN];

ld f(int i, int j, int k) {

    if(i + j + k == 0)
        return 0.0;
    if(dp[i][j][k] >= 0)
        return dp[i][j][k];
    
    dp[i][j][k] = (ld)n / (ld)(i + j + k);
    if(i)
        dp[i][j][k] += ((ld)i / (i + j + k)) * f(i - 1, j, k);
    if(j)
        dp[i][j][k] += ((ld)j / (i + j + k)) * f(i + 1, j - 1, k);
    if(k)
        dp[i][j][k] += ((ld)k / (i + j + k)) * f(i, j + 1, k - 1);
    return dp[i][j][k];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int br1 = 0, br2 = 0, br3 = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if(a == 1)
            br1++;
        else if(a == 2)
            br2++;
        else
            br3++;
    }

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            for(int k = 0; k < MAXN; k++)
                dp[i][j][k] = -1.0;
    cout << fixed << setprecision(10) << f(br1, br2, br3) << endl;
    return 0;
}
