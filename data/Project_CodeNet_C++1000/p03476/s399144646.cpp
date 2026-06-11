#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    vector<int> is_prime(100005,1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < 100005; i++) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < 100005; j+=i) is_prime[j] = 0;
    }
    vector<int> a(100005, 0);
    for (int i = 0; i < 100005; i++) {
        if (i % 2 == 0) continue;
        if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }
    vector<int> s(100006, 0);
    for (int i = 0; i < 100005; i++) s[i+1] = s[i] + a[i];
    int Q; 
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << s[r+1]-s[l] << endl;
    }
}