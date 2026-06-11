#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> s(n+1, vector<int>(n+1));

    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        s[l][r]++;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            s[i][j] += s[i][j-1];
        }
    }

    for(int i = 0; i < q; i++){
        int L, R;
        cin >> L >> R;
        int ans = 0;
        for(int j = L; j <= R; j++){
            ans += s[j][R];
        }
        cout << ans << endl;
    }
}