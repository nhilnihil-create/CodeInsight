#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(int n) {
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    else {
        for (int i = 3; i * i < n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

int main() {
    ll N, P;
    cin >> N >> P;

    map<ll, ll> div_counts;
    if (N == 1 || isPrime(P)) {
        div_counts[P] = 1;
    } else {
        for (ll i = 1; i * i <= P; i++) {
            if (isPrime(i)) {
                div_counts[i] = 0;
                while (P % i == 0) {
                    div_counts[i]++;
                    P /= i;
                }
            }
        }
    }

    ll ans = 1;
    for (auto& it : div_counts) {
        if (it.second >= N) 
            ans *= pow(it.first, it.second / N);
    }

    cout << ans << endl;
}