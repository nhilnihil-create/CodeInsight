#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)
//
const int mod = 1e9 + 7;
const int MX = 3002;
int dp[22][(1<<21)+1337]; // 1 - win, 0 - lose
int32_t main()
{
    
    int n;
    cin >> n;
    vector<vector<int>>g(n,vector<int>(n));
    forn(i,n){
        forn(j,n){
            cin >> g[i][j];
        }
    }
    dp[0][0]=1;
    forn(i,n){
        forn(j,(1 << n)){
            if (dp[i][j] == 0) {
                continue;
            }
            forn (k, n) {
                if (g[i][k] && (j & (1 << k)) == 0) {
                    dp[i + 1][j | (1 << k)] += dp[i][j];
                    dp[i + 1][j | (1 << k)] %= mod;
                }
            }
        }
    }
    cout << dp[n][(1 << n) - 1] << endl;
    return 0;
}