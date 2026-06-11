#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q; cin >> Q;
    int left = 100000, right = 1;
    vector<pair<int, int>> query;
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        query.push_back({l, r});
        left = min(l, left);
        right = max(r, right);
    }
    vector<bool> isPrime(right + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= right; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2; i * j <= right; j++) {
            isPrime[j * i] = false;
        }
    }
    vector<int> cum2017(right + 1, 0);
    for (int i = left; i <= right; i++) {
        if (isPrime[i] && isPrime[(i + 1) / 2]) cum2017[i] = cum2017[i-1] + 1;
        else cum2017[i] = cum2017[i-1];
    }
    for (int i = 0; i < Q; i++) {
        int l = query[i].first;
        int r = query[i].second;
        cout << cum2017[r] - cum2017[l - 1] << endl;
    }
}