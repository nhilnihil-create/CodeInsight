#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator
const int MXN = 1e5+1;
ll a[MXN], b[MXN], c[MXN], n, dp[MXN][3];

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    sort(c+1, c+n+1);
    for(int i=1;i<=n;i++) dp[i][0] = i;
    for(int i=1;i<=n;i++) {
        auto it = lower_bound(a+1, a+n+1, b[i]);
        dp[i][1] = dp[i-1][1] + dp[it-a-1][0];
    }
    for(int i=1;i<=n;i++) {
        auto it = lower_bound(b+1, b+n+1, c[i]);
        dp[i][2] = dp[i-1][2] + dp[it-b-1][1];
    }
    cout<< dp[n][2] << endl;    
}

int main() {
    solve();
    return 0;
}