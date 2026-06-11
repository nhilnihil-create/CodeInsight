#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  cin >> N;
    vector<long long> cnt(6);
    map<char, int> mp;
    mp['M'] = 1;  mp['A'] = 2;  mp['R'] = 3;  mp['C'] = 4;  mp['H'] = 5;
    for (int i = 0; i < N; ++i) {
        string s;  cin >> s;
        if (mp[s[0]]) ++cnt[mp[s[0]]];
    }
    long long ans = 0;
    for (int i = 1; i <= 5; ++i)
        for (int j = i + 1; j <= 5; ++j)
            for (int k = j + 1; k <= 5; ++k)
                ans += cnt[i] * cnt[j] * cnt[k];
    cout << ans << endl;
}
