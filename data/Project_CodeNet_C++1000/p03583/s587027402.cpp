#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long int64;

int main() {
    int64 N; cin >> N;
    for(int n = 1; n < 3501; ++n) {
        for(int w = 1; w < 3501; ++w) {
            int64 u = 4 * n * w - N * w - N * n;
            if(u <= 0) continue;
            int64 b = N * n * w;
            if(b % u) continue;
            int64 h = b / u;
            if(1 <= h && h <= 3500) {
                cout << h << " ";
                cout << n << " ";
                cout << w << '\n';
                return 0;
            }
        }
    }
    return 0;
}
