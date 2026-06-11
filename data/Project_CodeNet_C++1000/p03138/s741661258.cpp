
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, bit_k[63] = {}, bit_sum[63][2] = {};
    long long k, a, ans;
    bool islimit;

    cin >> n >> k;

    for(int i=0 ;i<63 ;i++ ) {
        bit_k[i] = k%2;
        k = k / 2;
    }

    for(int i=0 ;i<n ;i++) {
        cin >> a;

        for(int j=0 ;j<63 ;j++ ) {
            bit_sum[j][a%2] += 1;
            a = a / 2;
        }
    }

    islimit = true;
    ans = 0;
    for(int i=62 ;i>=0; i-- ) {
        ans = ans * 2;

        if(islimit) {
            if(bit_k[i] == 0) {
                ans += bit_sum[i][1];
            }
            else {
                if(bit_sum[i][1] > bit_sum[i][0]) {
                    islimit = false;       
                }
                ans += max(bit_sum[i][0], bit_sum[i][1]);
            }
        }
        else {
            ans += max(bit_sum[i][0], bit_sum[i][1]);
        }
    }

    cout << ans << '\n';
}