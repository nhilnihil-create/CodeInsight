#include<bits/stdc++.h>

using namespace std;

int main() {

    int N, T;
    cin >> N >> T;

    int c[N + 1], t[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> c[i] >> t[i];
    }

    int ans = 1001;

    for (int i = 1; i <= N; i++) {
        if(t[i] <= T) {
            if (c[i] <= ans) {
                ans = c[i];
            }
        }
    }

    if (ans == 1001) {
        cout << "TLE" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}