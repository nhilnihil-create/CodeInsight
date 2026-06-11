#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<tuple<string, int, int>> shop(N);
    string S;
    int P;
    for (int i = 0; i < N; i++) {
        cin >> S >> P;
        shop[i] = make_tuple(S, -P, i+1);
    }
    sort(shop.begin(), shop.end());
    for (int i = 0; i < N; i++) {
        cout << get<2>(shop[i]) << endl;
    }
}

int main() {
    solve();
    return 0;
}
