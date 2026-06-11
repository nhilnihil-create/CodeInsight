#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    rep(i, m) {
        cin >> l[i] >> r[i];
    }
    vector<int> left(m), right(m);
    int ans;
    bool flag = true;
    rep(i, m) {
        if (i == 0) {
            left[i] = l[i];
            right[i] = r[i];
          	if (right[i] > n) right[i] = n;
        } else {
            if (l[i] > right[i-1] || r[i] < left[i-1]) {
                flag = false;
                break;
            } else {
                if (l[i] > left[i-1]) left[i] = l[i];
                else left[i] = left[i-1];
                if (r[i] < right[i-1]) right[i] = r[i];
                else right[i] = right[i-1];
            }
        }
        
    }
    if (flag) {
        // if (right[m-1] <= n) {
            ans = right[m-1] - left[m-1] + 1;
        // } else if (left[m-1] >= n) {
        //     ans = n - left[m-1] + 1;
        // } else {
        //     ans = 0;
        // }
    } else {
        ans = 0;
    }
    cout << ans << endl;
}