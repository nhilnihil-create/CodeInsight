#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    int ans = 0;
    rep(i,N + 1) {
        if (i%2 == 1) {
            int count = 0;
            for (int j = 1; j < i + 1; j++) {
                if (i%j == 0) {
                    count++;
                }
            }
            if (count == 8) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

