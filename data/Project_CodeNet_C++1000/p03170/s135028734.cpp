#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100 + 5;
const int MAXK = 1e5 + 5;

int n, k, a[MAXN];
bool dp[MAXK];

int main() {
    IOS
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    sort(a, a + n);
    
    for (int i = 0; i <= k; i++) {
        if (!dp[i]) {
            for (int j = 0; j < n && i + a[j] <= k; j++) {
                dp[i + a[j]] = 1;
            }
        }
    }

    if (dp[k]) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}