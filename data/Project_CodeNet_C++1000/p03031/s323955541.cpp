#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k[10], s[10][10], p[10];
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> k[i];
        for(int j=0; j<k[i]; j++) {
            int x; cin >> x;
            s[i][x - 1]++;
        }
    }
    for(int i=0; i<m; i++) cin >> p[i];
    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++) {
        int as[m] = {0};
        bool flag = true;
        for(int i=0; i<n; i++) {
            if(bit>>i & 1) {
                for(int j=0; j<m; j++) as[j] += s[j][i];
            }
        }
        for(int j=0; j<m; j++) if(as[j] % 2 != p[j]) flag = false;
        if(flag) ans++;
    }
    cout << ans << endl;
}