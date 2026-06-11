#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL<<60);

int main() {
    int n, m;
    cin >> n >> m;
    long long data[n][3];
    for (int i = 0; i < n; i++) {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }
    
    long long ans = -INF;
    for (int bit = 0; bit < (1<<3); bit++) {
        vector<long long> v;
        for (int i = 0; i < n; i++) {
            long long s = 0;
            for (int j = 0; j < 3; j++) {
                if (bit&(1<<j)) s += data[i][j];
                else s -= data[i][j];
            }
            v.emplace_back(s);
        }
        sort(v.rbegin(), v.rend());
        long long res = accumulate(v.begin(), v.begin() + m, 0LL);
        if (ans < res) ans = res;
    }
    
    cout << ans << endl;
    return 0;
}