#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m, t1, t2, a[11], c[] = {999999,2,5,5,4,5,6,3,7,6};
int dp[10005], dp2[10005];

int f(int x) {
    if(x < 0)
        return -999999;

    if(x == 0)
        return 0;

    if(dp[x] != -1)
        return dp[x];

    int mx = -1, tz = -1;
    for(int i = 9; i >= 1; --i)
        if(a[i])
            if(f(x - c[i]) + 1 > mx) {
                mx = f(x - c[i]) + 1;
                tz = i;    
            }
    dp2[x] = tz;
    return dp[x] = mx;
}

void f2(int x) {
    if(!x)
        return;
    cout << dp2[x];
    f2(x - c[dp2[x]]);
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
        cin >> t1, a[t1] = 1;
    f(n);
    f2(n);
    return 0;
}