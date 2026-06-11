#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
    vector<int> b(m);
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int counter = c;
        for(int j = 0; j < m; j++) {
            counter += a[i][j] * b[j];
        }
        if(counter > 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}