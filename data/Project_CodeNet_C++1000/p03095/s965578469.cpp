#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MOD = 1e9 + 7;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    map<char, ll> memo;
    for (int i = 0; i < N; i++) memo[S[i]]++;
    ll ans = 1;
    for (auto x : memo) ans = (ans * (x.second + 1)) % MOD;
    cout << (MOD + ans - 1) % MOD << endl;
}
