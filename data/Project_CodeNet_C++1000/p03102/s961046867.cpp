#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m, c);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int ans = 0, temp;
    for(int i = 0; i < n; i++) {
        int temp2 = c;
        for(int j = 0; j < m; j++) {
            cin >> temp;
            temp2 += temp*b[j];
        }
        if(temp2 > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
