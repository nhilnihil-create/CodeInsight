#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<ll> cnt(26, 0);
    for (int i = 0; i < N; i++) {
        cnt[S[i] - 'a']++;
    }

    ll ans = 1;
    ll mod = 1e9 + 7;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0)
            continue;

        ans *= (cnt[i] + 1);
        ans %= mod;
    }
    cout << --ans << endl;
}
