#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, x;
    cin >> n >> d >> x;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans++;
        int temp = a[i]+1;
        while (temp <= d) {
            ans++;
            temp += a[i];
        }
    }
    ans += x;
    cout << ans << endl;
}