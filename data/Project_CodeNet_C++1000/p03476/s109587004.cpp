#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int q; cin >> q;

    int MAX = 101010;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
    }

    vector<int> a(100001);
    for (int i = 1; i < 100000; i++) {
        if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }
    vector<int> s(100001);
    for (int i = 0; i < 100001; i++) {
        s[i+1] = s[i] + a[i];
    }


    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << s[r+1] - s[l] << endl;
    }
}
