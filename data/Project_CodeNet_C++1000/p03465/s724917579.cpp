
#include <bits/stdc++.h>
using namespace std;

const int N = 2000*2000+10;
bitset<N> memo;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    memo[0] = 1;
    for(int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        sum += val;
        memo |= (memo<<val);
    }
    for(int i = (sum+1)/2;; ++i) {
        if(memo[i]) {
            cout << i;
            return 0;
        }
    }
}
