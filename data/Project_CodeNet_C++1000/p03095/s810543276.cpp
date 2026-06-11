#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll N;
    ll ans = 1;
    cin >> N;
    string S;
    cin >> S;
    map<char, int>m;
    for (int i = 0; i < N; i++) {
        m[S[i]]++;
    }
    for (auto x : m) {
        ans *= (1+x.second);
        ans %= mod;
    }
    cout << ((ans - 1)+mod) % mod << endl;
}
