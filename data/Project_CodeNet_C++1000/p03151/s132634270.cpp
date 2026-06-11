#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<int64_t> margins;
    int64_t sum_margin = 0;
    int64_t sum_lack = 0;
    int ans = 0;
    bool all_ok = true;
    rep(i,n) {
        if (a[i] > b[i]) {
            int margin = a[i] - b[i];
            sum_margin += margin;
            margins.push_back(margin);
        }
        if (a[i] < b[i]) {
            sum_lack += b[i] - a[i];
            ans++;
            all_ok = false;
        }
    }
    sort(margins.begin(), margins.end(), greater<>());
    vector<int64_t> cumulative_sum(margins.size()+1, 0);
    rep(i,margins.size()) cumulative_sum[i+1] = cumulative_sum[i] + margins[i];
    if (sum_margin < sum_lack) ans = -1;
    else {
        ans += lower_bound(cumulative_sum.begin(), cumulative_sum.end(), sum_lack) - cumulative_sum.begin();
    }
    if (all_ok) ans = 0;
    cout << ans << endl;
}