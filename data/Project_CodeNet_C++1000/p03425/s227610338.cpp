#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long cnt[10] = {};
    string pattern = "MARCH";
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < 5; j++) {
            if (S[0] == pattern[j]) cnt[j]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }

    cout << ans << endl;
}