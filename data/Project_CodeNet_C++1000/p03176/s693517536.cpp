#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> h(n+1, 0), a(n+1, 0);
    vector<long long> dp(n+1, 0);
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1;i<=n;i++) cin >> a[i];
    long long ans = 0;
    for(int i=1;i<=n;i++){
        long long res = 0;
        int x = h[i];
        while(x > 0){
            if(res < dp[x]) res = dp[x];
            x -= (x & -x);
        }
        res += a[i];
        x = h[i];
        while(x <= n){
            if(dp[x] < res) dp[x] = res;
            x += (x & -x);
        }
        if(ans < res) ans = res;
    }
    cout << ans << endl;
}
