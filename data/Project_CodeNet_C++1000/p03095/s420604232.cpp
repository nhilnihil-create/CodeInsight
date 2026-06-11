#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt[26];
    for (int i = 0; i < 26; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
    long long ans = 1;
    for (int i = 0; i < 26; ++i) {
        ans *= (long long)(cnt[i] + 1);
        ans %= mod;
    }
    cout << (ans ? --ans : --ans + mod) << endl;
}