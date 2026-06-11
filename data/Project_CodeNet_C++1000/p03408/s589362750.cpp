#include <bits/stdc++.h>

using namespace std;

int N, M;
string s[100], t[100];

void solve() {
    map<string, int> values;
    for (int i = 0; i < N; ++i) {
        values[s[i]] = 0;
    }
    for (int i = 0; i < M; ++i) {
        values[t[i]] = 0;
    }
    for (int i = 0; i < N; ++i) {
        values[s[i]] += 1;
    }
    for (int i = 0; i < M; ++i) {
        values[t[i]] -= 1;
    }
    int max = 0;
    for (const auto &x : values) {
        if (max < x.second) max = x.second;
    }
    printf("%d\n", max);

}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }
    cin >> M;
    for (int j = 0; j < M; ++j) {
        cin >> t[j];
    }
    solve();
    return 0;
}