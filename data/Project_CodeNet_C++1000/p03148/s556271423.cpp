#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int> > all(n);
    for (int i = 0; i < n; i++)
        cin >> all[i].second >> all[i].first;
    sort(all.rbegin(), all.rend());
    long long sum = 0, count = 0;
    int used[n+1];
    fill(used, used+n+1, 0);
    for (int i = 0; i < k; i++) {
        sum += all[i].first;
        if (used[all[i].second] == 0) count++;
        used[all[i].second]++;
    }
    long long ans = sum + count * count;
    for (int i = k, j = k-1; i < n && count < k; i++) {
        if (used[all[i].second] == 0) {
            while (used[all[j].second] <= 1) j--;
            sum += all[i].first - all[j].first;
            used[all[i].second]++;
            used[all[j].second]--;
            count++;
            ans = max(ans, sum + count * count);
            j--;
        }
    }
    cout << ans << endl;
}
