#include <bits/stdc++.h>
using namespace std;

long long min_ans(const vector<long long>&a) {
    long long res = 2;
    for (auto& e : a) if (res%e != 0) res = res - (res%e) + e;
    return res;
}



int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& e : a) cin >> e;
    reverse(a.begin(), a.end());
    
    auto is_ok = [&](long long k) {
        for (auto e : a) k = k - (k % e);
        return k == 2;
    };
    
    long long mn = min_ans(a);
    reverse(a.begin(), a.end());
    
    if (is_ok(mn)) {
        long long ok = mn, ng = 1e18;
        while (abs(ok - ng) > 1) {
            long long mid = (ok + ng) / 2;
            if (is_ok(mid)) ok = mid;
            else ng = mid;
        }
        cout << mn << " " << ok << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}