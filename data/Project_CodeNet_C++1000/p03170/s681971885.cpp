#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[100+10], memo[100000+10];
int go(int rem) {
    if (rem==0) return 0;
    if (memo[rem] != -1) return memo[rem];
    for (int i = 0; i < n; i++) {
        if (rem < a[i]) continue;
        int nxt = go(rem-a[i]);
        if (nxt % 2 == 0 && a[i] <= rem) { 
            return memo[rem] = nxt+1; // nxt is ev but the one step to get there makes it even
        }
    }
    return memo[rem] = 12;  // any even num
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(memo, -1, sizeof memo);
    if (go(k)%2 == 1) cout << "First";
    else cout << "Second";

    return 0;
}