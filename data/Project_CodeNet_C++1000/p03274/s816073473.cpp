#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n, k;
    cin >> n >> k;
    vector<long long> pos, neg;
    pos.push_back(0);
    while(n--) {
        long long x;
        cin >> x;
        if (x >= 0) {
            pos.push_back(x);
        }
        else {
            neg.push_back(-1 * x);
        }
    }
    neg.push_back(0);
    reverse(neg.begin(), neg.end());
    long long ans = INT_MAX;
    for (int i = 0, j = k; i <= k; i++, j--) {
        if(i >= (int) neg.size() || j >= pos.size()) {
            continue;
        }
        if(neg[i] > pos[j]) {
            swap(neg[i], pos[j]);
        }
        ans = min(ans, (neg[i] * 2) + pos[j]);
    }
    cout <<  ans;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
