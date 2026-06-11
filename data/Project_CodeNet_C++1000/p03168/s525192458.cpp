#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define oo 1e7
using namespace std;
typedef long long ull;
typedef pair<int, int> ii;
typedef pair<long double, int> id;
typedef pair<long long, long long> llp;
const int N = 3*1e3+1;
const long long MOD = 1e9;
int n, m, t, k;
double dp[N];
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("nangcap.inp", "w", stdout);
    fastIO;
    cin>>n;
    dp[0] = 1;
    double phead, ans = 0;
    for(int i=1;i<=n;i++) {
        cin>>phead;
        for(int j=i+1;j>=0;j--) dp[j] = (j==0?0:dp[j-1]*phead) + dp[j]*(1-phead);
    }
    for(int i=0;i<=n;i++) {
        if (i>n-i) ans+=dp[i];
    }
    cout << setprecision(10) << fixed << ans;
}
