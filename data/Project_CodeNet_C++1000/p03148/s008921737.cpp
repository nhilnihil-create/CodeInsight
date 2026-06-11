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

    long long ans = 0;
    for (long long x = 0; x <= min(k, (int)top_d.size()); x++) {
        if ((int)other.size() < k - x) continue;
        
        long long sum = 0;
        for (int i = 0; i < x; i++) {
            sum += top_d.at(i);
        }
        for (int i = 0; i < k - x; i++) {
            sum += other.at(i);
        }

        ans = max(ans, sum + x * x);
    }
    cout << ans << endl;
}  