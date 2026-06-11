#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t n, m;
    cin >> n >> m;
    vector<pair<int64_t ,int64_t>> p(n); 

    for (int i = 0; i < n; i++) {
        cin >> p.at(i).first >> p.at(i).second;
    }

    sort(p.begin(), p.end());

    int64_t count = 0;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        if(count + p.at(i).second <= m) {
            count += p.at(i).second;
            ans += p.at(i).first * p.at(i).second;
        }
        else {
            ans += p.at(i).first * (m - count);
            break;
        }
    }

    cout << ans << endl;


}