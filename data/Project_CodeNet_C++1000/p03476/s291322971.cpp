#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int MAX_N = 100001;
vector<int>is_prime(MAX_N, 1);

int Eratosthenes(int MAX_N) {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if(is_prime[i]) {
            for (int j = 2 * i; j <= MAX_N; j += i ) {
                is_prime[j] = 0;
            }
        }
    }   
}

int main() {
    int q;
    cin >> q;

    Eratosthenes(MAX_N);

    vector<int> a(MAX_N, 0);
    for (int i = 0; i <MAX_N; i++) {
        if (i % 2 == 0 ) continue;
        if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }

    vector<int> s(MAX_N+1, 0);
    rep(i, MAX_N) s[i+1] = s[i] + a[i];

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        r++;
        cout << s[r] - s[l] << endl;
    }
    return 0;
}