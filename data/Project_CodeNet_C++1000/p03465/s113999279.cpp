#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5, M = 4e6 + 5;

int n, sum;
int a[N];
bitset <M> dp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp[0] = true;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        dp |= (dp << a[i]);
    }
    int x = (sum + 1) / 2;
    while (1){
        if (dp[x]) return cout << x, 0;
        x++;
    }
}