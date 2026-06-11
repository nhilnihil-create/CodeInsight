#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        a.at(t - 1).push_back(d);
    }
    for (int i = 0; i < n; i++) {
        sort(a.at(i).rbegin(), a.at(i).rend());
    }

    vector<long long> top_d, other;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)a.at(i).size(); j++) {
            if (j == 0) top_d.push_back(a.at(i).at(j));
            else other.push_back(a.at(i).at(j));
        }
    }

    sort(top_d.rbegin(), top_d.rend());
    sort(other.rbegin(), other.rend());

    long long sum = 0;
    int r1 = min(k, (int)other.size()), r2 = k - r1;
    for (int i = 0; i < r1; i++) {
        sum += other.at(i);
    }
    for (int i = 0; i < r2; i++) {
        sum += top_d.at(i);
    }
    
    long long ans = sum + (long long)r2 * r2;

    for (int i = 0; i < k; i++) {
        r1--;
        if (r1 < 0 || (int)top_d.size() <= r2) break;
        
        sum -= other.at(r1);
        sum += top_d.at(r2);
        r2++;
        ans = max(ans, sum + (long long)r2 * r2);
    }
    cout << ans << endl;
}  