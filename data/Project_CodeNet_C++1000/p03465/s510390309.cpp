#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
bitset<maxn * maxn> dp;
int main()
{
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    dp[0] = 1;
    int sum = 0;
    for (int i = 1 ; i <= n ; i++){
        int a ; cin >> a;
        dp |= (dp << a);
        sum += a;
    }
    int ans = 0 ,low = (sum - 1) / 2 + 1;
    for (int i = low ; i <= sum ; i++){
        if (dp[i]){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}