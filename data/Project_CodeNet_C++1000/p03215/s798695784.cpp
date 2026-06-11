#include <bits/stdc++.h>

using namespace std;

const int max_n = 10111, inf = 1000111222;

int n, k, a[max_n];
long long ans;
vector<long long> v;

bool get_bit(long long x, int pos) {
    return (x >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j];
            v.push_back(sum);
        }
    }
    for (int b = 55; b >= 0; --b) {
        int cnt = 0;
        for (long long x : v) {
            if ((x & ans) == ans) {
                cnt += get_bit(x, b);
            }
        }
        if (cnt >= k) {
            ans += 1LL << b;
        }
    }
    cout << ans << endl;
    return 0;
}
