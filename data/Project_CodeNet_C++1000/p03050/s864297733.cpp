#include <bits/stdc++.h>
using namespace std;

template<typename T> vector<T> divisor(T n){
    vector<T> res;
    for (long long i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) { res.emplace_back(n/i); }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    long n;
    cin >> n;
    vector<long> d = divisor(n);
    
    long ans = 0;
    for (const long &e : d) {
        if (e == 1) continue;
        const long p = n / (e - 1);
        const long q = n % (e - 1);
        if (p == q) ans += e - 1;
    }
    
    cout << ans << '\n';
    return 0;
}