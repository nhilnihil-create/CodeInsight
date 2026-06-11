#include <bits/stdc++.h>
using namespace std;
#define int long long

int v[21], c[21];

signed main() {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i+=1){
        if (v[i] - c[i] > 0) {
            ans = ans + v[i] - c[i];
        }
    }
    cout << ans << endl;
    return 0;

}