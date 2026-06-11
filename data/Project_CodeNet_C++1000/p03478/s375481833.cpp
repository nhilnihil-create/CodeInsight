#include <bits/stdc++.h>

using namespace std;

int N;
int A, B;

void solve() {
    int res = 0;
    for (int j = 1; j <= N; ++j) {
        string s = to_string(j);
        int num = 0;
        for (int i = 0; i < int(s.size()); ++i) {
            num += s[i] - '0';
        }
        if (A <= num && num <= B) {
            res += j;
        }
    }
    printf("%d\n", res);
}

int main() {
    cin >> N >> A >> B;
    solve();
    return 0;
}