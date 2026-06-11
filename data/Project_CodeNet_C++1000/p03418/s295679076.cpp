#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, k; cin >> n >> k;
    ll ans = 0;
    int tmp;
    for(int i = 1; i <= n - k; i++){
        tmp = n;
        int b = k + i;
        ans += tmp/b*i;
        int cnt = tmp % b;
        if(cnt == 0) continue;
        if(k == 0) ans += (cnt >= k? cnt - k: 0);
        if(k > 0) ans += (cnt >= k? cnt - k + 1: 0);
    }
    cout << ans << endl;

}