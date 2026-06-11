#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type, less_equal<int>,rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;
const int N = 2e5 + 5;
int n , f[105][10];
int p[105][11] , c[1 << 10];
int memo[10][1 << 10];
int solve(int i , int mask) {
    if(i == 10)
        return mask ? c[mask] : -2e9;
    int &ans = memo[i][mask];
    if(~ans)
        return ans;
    return ans = max(solve(i + 1 , mask) , solve(i + 1 , mask | (1 << i)));
}
int main() {
    abdelrahman010
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0; j < 10;j++)
                cin >> f[i][j];
    for(int i = 0;i < n;i++)
        for(int j = 0;j <= 10;j++)
            cin >> p[i][j];
    for(int i = 0;i < (1 << 10);i++)
        for(int j = 0;j < n;j++) {
            int cnt = 0;
            for(int k = 0;k < 10;k++)
                cnt += (((1 << k) & i) && f[j][k]);
            c[i] += p[j][cnt];
        }
    memset(memo , -1 , sizeof memo);
    cout << solve(0 , 0);
    return 0;
}
