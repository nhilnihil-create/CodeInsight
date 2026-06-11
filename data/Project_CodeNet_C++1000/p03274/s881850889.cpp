#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k; vector<int64_t> mx, px;
    for (auto i = 0; i < n; i++) {
        int x; cin >> x;
        if(x > 0) px.push_back(x);
        else if(x < 0) mx.push_back(abs(x));
        else k--;
    }
    reverse(mx.begin(), mx.end());
    if(k == 0) { cout << 0 << endl; return 0; }
    int64_t ans = min(((int)px.size() >= k ? px[k - 1] : INT64_MAX),
                       (int)mx.size() >= k ? mx[k - 1] : INT64_MAX);
    for (auto i = 1; i < k; i++) {
        if ((int) mx.size() < i) continue;
        if ((int) px.size() < k - i) continue;
        int64_t left = mx[i - 1] * 2 + px[k - i - 1],
                right = mx[i - 1] + px[k - i - 1] * 2;
        ans = min(ans, min(left, right));
//        cout << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}