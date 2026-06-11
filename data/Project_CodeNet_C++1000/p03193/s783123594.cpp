#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

int main() {
    int n, h, w;
    cin >> n >> h >> w;
    int a, b;
    int t = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a >= h && b >= w) {
            t++;
        }
    }
    cout << t << endl;
}
