//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stweight++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include <fstream>


using namespace std;

const int N = 5000 + 5;
long long dp[N][N];
int p[N];
int a;
int b;
int n;
 
int main () 
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    memset(dp, 127, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1;i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(p[i] > j)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
                dp[i][p[i]] = min(dp[i][p[i]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = min(dp[i][j],dp[i-1][j] + b);
            }
        }
    }
    long long ans = dp[n][1];
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}


