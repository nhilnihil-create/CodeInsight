//
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>
//#ifdef atom #else #endif
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define X first
#define Y second
#define vi vector<int>
#define vvi vector< vi >
#define vii vector< ii >
#define mp make_pair
#define pb push_back
string s;
int k;
const int maxn = 305;
const int maxk = 305;
int dp[maxn][maxn][maxk];
int n;
int solve(int i, int j, int k)
{
    if(i> j) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int add = 2;
    int res = 0;
    if(i == j) add = 1;
    res = max(res, solve(i+1, j, k));
    res = max(res, solve(i, j-1, k));
    if(s[i] == s[j]) res = max(res, add+solve(i+1, j-1, k));
    if(k) res = max(res, add+solve(i+1, j-1, k-1));
    return dp[i][j][k] = res;
}
int main()
{
    //#ifndef atom freopen(".in", "r", stdin); freopen(".out", "w", stdout); #endif
    cin >> s >> k;
    n = s.size();
    memset(dp, -1, sizeof dp);
    //cout << solve(1, 4, 0) << endl;
    cout << solve(0, n-1, k) << endl;
}
