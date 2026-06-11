#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int a,b,c,x; cin >> a >> b >> c >> x;
    int ans = 0;
    for (int i500 = 0; i500 <= a; i500++) {
        for (int i100 = 0; i100 <= b; i100++) {
            for (int i50 = 0; i50 <= c; i50++) {
                if (i500*500 + i100*100 + i50*50 == x) {
                    ans ++;
                }
            }
            // int t = x - i500*500 + i100*100;
            // if (t >= 0 and t%50==0 and t/50 <= c) {
            //     ans++;
            //}
        }
    }
    cout << ans << endl;
}