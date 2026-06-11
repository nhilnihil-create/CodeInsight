#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; i++) cin >> D[i];
    sort(D.begin(), D.end());
    int n, p;
    n = p = 0;
    for (int x = 12; x >= 0; x--) {
        bool possible = true;
        n = p = 0;
        for (int i = 0; i < N; i++) {
            if (p + x > D[i] && n - x < -D[i])
                possible = false;
            else if (p + x > D[i])
                n = -D[i];
            else if (n - x < -D[i])
                p = D[i];
            else {
                if (p >= -n) p = D[i];
                if (p < -n) n = -D[i];
            }
        }
        possible &= (p <= 12 && n >= -12 && 24 + n - p >= x);
        if (possible) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}