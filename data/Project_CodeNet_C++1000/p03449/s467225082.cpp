#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i=0; i<2; i++){
        for (int j=0; j<n; j++) cin >> a[i][j];
    }
    for (int i=1; i<n; i++){
        a[0][i] += a[0][i-1];
        a[1][n-1-i] += a[1][n-i];
    }
    int ans = 0;
    for (int i=0; i<n; i++){
        ans = max(ans, a[0][i]+a[1][i]);
    }
    cout << ans << endl;
    return 0;
}