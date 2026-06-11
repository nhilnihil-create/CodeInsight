#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return (t * t) % mod;
    } else {
        return (modpow(m, n - 1) * m) % mod;
    }
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

signed main() {
    long long n, m, ans = 0;
    cin >> n >> m;
    vector<long long> as(m);
    vector<long long> bs(m);
    vector<long long> ansv(m);
    ans = n * (n - 1) / 2;
    REP(i, m) {
        cin >> as[i] >> bs[i];
        as[i] -= 1;
        bs[i] -= 1;
    }
    reverse(as.begin(), as.end());
    reverse(bs.begin(), bs.end());
    vector<long long> parent(n, -1);
    vector<long long> size(n, 1);
    ansv[0] = ans;
    REP(i, m - 1) {
        long long k = as[i];
        while (parent[k] != -1) {
            k = parent[k];
        }
        long long l = bs[i];
        while (parent[l] != -1) {
            l = parent[l];
        }
        if (l != k) {
            if (size[k] <= size[l]) {
                swap(k, l);
            }
            parent[l] = k;
            ans -= size[l] * size[k];
            ansv[i + 1] = ans;
            size[k] += size[l];
        }else{
            ansv[i + 1] = ansv[i]; 
        }
    }
    reverse(ansv.begin(), ansv.end());
    REP(i, m) { cout << ansv[i] << endl; }
}