#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;

    for (int r=0; r<=N/R; r++) {
        for (int g=0; g<=(N-R*r)/G; g++) {
            if ((N-R*r-G*g) % B == 0) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}