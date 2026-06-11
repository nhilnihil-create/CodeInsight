#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, ans = 1; cin >> n; int pre[n+2]={}, pos[n+2]={}, a[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = __gcd(pre[i-1], a[i]);
    }

    for(int i = n; i >= 1; i--) pos[i] = __gcd(pos[i+1], a[i]);

    for(int i = 1; i <= n; i++) ans = max(ans, __gcd(pre[i-1], pos[i+1]));

    cout << ans;
}