#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q; 
    cin >> n >> m >> q;
    vector<vector<int>> sum(n+1, vector<int>(n+1, 0) );
    for (int i = 0; i < m; i++){
        int left, right;
        cin >> left >> right;
        sum[left][right] = sum[left][right] + 1;
    }
    
    for (int k = 1; k < n; k++){
        for (int l = 1; l+k <= n; l++){
            int r = l + k;
            sum[l][r] = sum[l][r] + sum[l+1][r] + sum[l][r-1] - sum[l+1][r-1];
        }   
    }

    for (int i = 0; i < q; i++){
        int p1, p2;
        cin >> p1 >> p2;
        cout << sum[p1][p2] << endl;
    }

    return 0;
}
