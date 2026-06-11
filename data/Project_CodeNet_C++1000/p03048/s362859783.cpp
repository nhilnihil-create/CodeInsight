#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    int d = n / r;
    for(int i = 0; i <= d; i++) {
        int rest = n - r * i;
        int d2 = rest / g;
        for(int j = 0; j <= d2; j++) {
            int rest2 = rest - g * j;
            if(rest2 % b == 0) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}