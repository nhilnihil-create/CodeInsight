#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++)
            ans = max(ans, abs(a[j]-a[i]));
    }

    cout << ans << endl;
}