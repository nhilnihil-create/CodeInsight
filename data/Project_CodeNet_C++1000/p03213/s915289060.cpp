#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> PRIMES;
void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (is_prime(i))
            PRIMES.push_back(i);
    }
}

vector<int> primes(int n) {
    vector<int> ret;
    for (int p : PRIMES) {
        if (n % p == 0) {
            n /= p;
            ret.push_back(p);
            while (n % p == 0) {
                n /= p;
                ret.push_back(p);
            }
        }
        if (n == 1) {
            break;
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    init(n);
    map<int, int> mp;
    for (int i = 2; i <= n; i++) {
        vector<int> pr = primes(i);
        for (int p : pr) {
            if (mp.count(p))
                mp[p]++;
            else
                mp[p] = 1;
        }
    }
    int ans = 0;
    // 2 4 4
    int c2 = 0;
    int c4 = 0;
    int c14 = 0;
    int c24 = 0;
    int c74 = 0;
    for (auto m : mp) {
        if (m.second >= 74) {
            c74++;
        }
        if (m.second >= 24) {
            c24++;
        }
        if (m.second >= 14) {
            c14++;
        }
        if (m.second >= 4) {
            c4++;
        }
        if (m.second >= 2) {
            c2++;
        }
    }
    if (c4 >= 2) {
        ans += (c2 - 2) * (c4 - 1) * c4 / 2;
    }
    if (c14 >= 1) {
        ans += (c4 - 1) * c14;
    }
    if (c24 >= 1) {
        ans += (c2 - 1) * c24;
    }
    if (c74 >= 1) {
        ans += c74;
    }
    cout << ans;
    return 0;
}
