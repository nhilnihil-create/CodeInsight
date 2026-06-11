#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    //入力
    int n;
    int a[2][101];
    int ans = 0;
    cin >> n;
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) cin >> a[i][j];
    }
    for (int i=0; i<n; i++) {
        int temp = 0;
        for (int j=0; j<=i; j++) temp += a[0][j];
        for (int j=i; j<n; j++) temp += a[1][j];
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}