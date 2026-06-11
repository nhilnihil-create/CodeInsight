#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for (int i = 0; i <= 3000; i++) {
        if (i*r > n) continue;
        for (int j = 0; j <= 3000; j++) {
            if (i*r+j*g > n) continue;
            int rem = n - (i*r+j*g);
            if (rem % b == 0) ans++;
        }
    }
    cout << ans << '\n';
}
