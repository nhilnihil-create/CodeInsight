#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

template<class T>
vector<pair<T, T>> PrimeFactorization(T n) {
    vector<pair<T, T>> f;
    for (T i = 2; i * i <= n; i++) {
        T cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) f.push_back(make_pair(i, cnt));
    }
    if (n != 1) f.push_back(make_pair(n, 1));
    return f;
}

int main() {
    int N; cin >> N;
    
    int factors[101] = {};
    for (int i = 1; i <= N; i++) {
        auto f = PrimeFactorization(i);
        for (auto elm : f) factors[elm.first] += elm.second;
    }

    map<int, int> m = {
        {3, 0},
        {5, 0},
        {15, 0},
        {25, 0},
        {75, 0},
    };

    for (int i = 1; i <= 100; i++) {
        for (auto &elm : m) {
            if (factors[i] + 1 >= elm.first) elm.second++; 
        }
    }

    // for (auto elm : m) cout << elm.first << " " << elm.second << endl;

    int ans = 0;
    ans += m[75];
    ans += m[25] * (m[3] - 1);
    ans += m[15] * (m[5] - 1);
    ans += (m[5] * (m[5] - 1)) / 2 * (m[3] - 2);
    cout << ans << endl;
    return 0;
}