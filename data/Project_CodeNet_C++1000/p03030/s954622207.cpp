#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<pair<pair<string, int>, int>> p(N);
    string S;
    int P;
    for (int i = 0; i < N; i++) {
        cin >> S >> P;
        p[i] = make_pair(make_pair(S, -P), i+1);
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < N; i++) {
        cout << p[i].second << endl;
    }
}

int main() {
    solve();
    return 0;
}