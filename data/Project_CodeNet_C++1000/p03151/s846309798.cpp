#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    long long int a[n], b[n], sum_a = 0, sum_b = 0, sum_less = 0;
    vector<long long int> over;
    for(int i = 0; i < n; ++i) cin >> a[i], sum_a += a[i];
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
        sum_b += b[i];
        if(a[i] < b[i]) ans++, sum_less += b[i] - a[i];
        else over.push_back(a[i] - b[i]);
    }
    if(sum_a < sum_b) {
        cout << -1 << '\n';
        return 0;
    }
    if(sum_less == 0) {
        cout << 0 << '\n';
        return 0;
    }
    sort(over.rbegin(), over.rend());
    for(int i = 0; i < over.size(); ++i) {
        sum_less -= over[i];
        ans++;
        if(sum_less < 0) break;
    }
    cout << ans << '\n';
    return 0;
}
