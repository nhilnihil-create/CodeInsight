#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> f(n,vector<int>(10)),p(n,vector<int>(11));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> f[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 11; j++) {
            cin >> p[i][j];
        }
    }
    long long ans = -100000000000;
    for(int i = 0; i < (1<<10); i++) {
        int counter = 0;
        if(__builtin_popcount(i) == 0) {
            continue;
        }
        for(int j = 0; j < n; j++) {
            int open = 0;
            for(int k = 0; k < 10; k++) {
                if((i >> k) & 1) {
                    if(f[j][k] == 1) {
                        open++;
                    }
                }
            }
            counter += p[j][open];
        }
        ans = max(ans,(long long)counter);
    }
    cout << ans << "\n";
    return 0;
}